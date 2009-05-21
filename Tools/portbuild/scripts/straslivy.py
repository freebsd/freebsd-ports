#!/usr/bin/env python

# Initially by pav, refactored by kris
#
# XXX Todo: handle ipv6 sockets (used by e.g. sparc64)

import commands
import socket
import sys

archwidth = branchwidth = portwidth = hostwidth = 0

def getpdispatch():
	""" get list of pdispatch processes """

	global archwidth, branchwidth, portwidth;

	args = sys.argv
	data = {}

	cmd = 'pgrep -lf "pdispatch '+' '.join(args[1:])+'"'
	for line in commands.getoutput(cmd).splitlines():
		if line.count('pgrep -lf "pdispatch'):
			continue;
		fields = line.split()
		pid = fields[0]
		arch = fields[3]
		branch = fields[4]
		port = fields[9].replace('/usr/ports/','')
		line = ' '.join(fields)

		if len(arch) > archwidth:
			archwidth = len(arch)
		if len(branch) > branchwidth:
			branchwidth = len(branch)
		if len(port) > portwidth:
			portwidth = len(port)

		data[pid] = {'arch': arch, 'branch': branch, 'port': port}
		if branch == 'pgrep':
			print line
	return data

def getparent(ppid_map, pid):
	"""walk up the ppid tree and return the parent pdispatch"""
 
	next = pid
	while ppid_map.has_key(next):
		next = ppid_map[next]['ppid']
	return next

def getallsubprocs(pids):
	"""recursively find all subprocs of the list in pids"""

	ppids = []
	nppids = pids
	while len(nppids):
		pidlist=",".join(nppids)
		nppids = commands.getoutput('pgrep -P ' + pidlist).splitlines()
		ppids.extend(nppids)
	return ppids

def dosubprocs(data):
	""" recursively get list of subprocesses (ptimeout.host, sleep 15, ...) and fill in data """

	ppid_map = { }
	idlers = { }

	ppid_arg = ",".join(getallsubprocs(data.keys()))
	list = commands.getoutput('ps ax -o pid,ppid,etime,command -p ' + ppid_arg).splitlines()[1:]
	for line in list:
		fields = line.split()
		pid = fields.pop(0)
		ppid = fields.pop(0)
		time = fields.pop(0)
		command = ' '.join(fields)
		if command.count('ptimeout.host'):
			command = "building"
		elif command == 'sleep 15':
			command = "waiting for idle node"
			idlers[ppid] = ppid
		elif command.count('scripts/clean-chroot'):
			command = "cleaning up the node"
		elif command.count('scripts/claim-chroot'):
			command = "preparing node"
		elif command.count('tar --unlink'):
			command = "copying package"
		elif command.count('buildsuccess'):
			command = "registering success"
		elif command.count('buildfailure'):
			command = "registering failure"
		elif command.count('scp ') and command.count('.log '):
			command = "copying logs"
		elif command.count('ssh'):
			command = "building"
		ppid_map[pid] = {'ppid':ppid, 'command':command, 'time':time}

	# fill in sleeper's parent pid etimes so we display how long the pdispatch
	# has been trying to acquire a chroot, instead of the <15 second sleep
	# lifetime
	if len(idlers):
		ppid_arg = ','.join(idlers)
		lines = commands.getoutput('ps ax -o pid,etime -p ' + ppid_arg).splitlines()[1:]
		for line in lines:
			fields = line.split()
			ppid = fields[0]
			time = fields[1]
			data[ppid]['time'] = time

	# Propagate commands and runtime to parent pdispatch.  We have
	# to do this after the loop above because ps sorts it output
	# and we are not guaranteed to have processes the ppid before
	# the pid.  The alternative is multiple ps invocations which
	# is slower.
	for pid in ppid_map.iterkeys():
		pppid = getparent(ppid_map, pid) # Find ancestor pdispatch
		ppid_map[pid].update({'pppid':pppid})
		blob = data[pppid]

		# propagate command and time to parent if necessary
		if not blob.has_key('command'):
			blob['command'] = ppid_map[pid]['command']
		if not blob.has_key('time'):
			blob['time'] = ppid_map[pid]['time']

	return ppid_map

# get list of network sockets and match to pdispatch children
def getsockets(ppid_map, data):
	global hostwidth

	# XXX what about ipv6?
	s = commands.getoutput('sockstat -4 -c')
	list = s.splitlines()
	list.pop(0)
	for line in list:
		line = line[20:]
		fields = line.split()
		spid = fields.pop(0)
		if len(fields) < 3:
			continue
		tuple = fields.pop(3)
		if tuple.find(':') == -1:
			continue
		(host, port) = tuple.split(':')

		# Check if the socket belongs to one of our pids
		if ppid_map.has_key(spid):
			ppid = ppid_map[spid]['pppid'] # Map to pdispatch
			if data.has_key(ppid):
				try:
					(hostname, bork, bork) = socket.gethostbyaddr(host)
				except socket.herror:
					hostname = host
				blob = data[ppid]
				blob['host'] = hostname
				if len(hostname) > hostwidth:
					hostwidth = len(hostname)

if __name__ == "__main__":
	data = getpdispatch()

	if len(data) == 0:
		print "No matching jobs"
		sys.exit()
	pids = data.keys()

	ppid_map = dosubprocs(data)
	getsockets(ppid_map, data)

	# format for output
	output = [ ]
	for pid in data:
		blob = data[pid]
		if not blob.has_key('host'):
			blob['host'] = ''
		if not blob.has_key('command'):
			blob['command'] = 'Dispatching'
		if not blob.has_key('time'):
			blob['time'] = '00:00'

		output.append(blob['arch'].ljust(archwidth + 2) + \
				      blob['branch'].ljust(branchwidth + 2) + \
				      blob['port'].ljust(portwidth + 2) + \
				      blob['host'].ljust(hostwidth + 2) + \
				      blob['command'] + " (" + blob['time'] + ")")
		
	# sort, output
	output.sort()
	print '\n'.join(output)
