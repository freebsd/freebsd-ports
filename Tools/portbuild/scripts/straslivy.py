#!/usr/bin/env python

import commands
import socket
import sys

# get list of pdispatch processes
args = sys.argv
del args[0]
s = commands.getoutput('pgrep -lf "pdispatch '+' '.join(args)+'"')
lines = s.splitlines()
pids = [ ]
data = { }
archwidth = branchwidth = portwidth = hostwidth = 0
for line in lines:
	if line.count('pgrep -lf "pdispatch'):
		continue;
	fields = line.split()
	pid = fields.pop(0)
	arch = fields[2]
	branch = fields[3]
	port = fields[6].replace('/usr/ports/','')
	line = ' '.join(fields)
	pids.append(pid)
	if len(arch) > archwidth:
		archwidth = len(arch)
	if len(branch) > branchwidth:
		branchwidth = len(branch)
	if len(port) > portwidth:
		portwidth = len(port)
	blob = {'arch': arch, 'branch': branch, 'port': port}
	data[pid] = blob
	if branch == 'pgrep':
		print line

for pid in data:
	blob = data[pid]

# get list of subprocesses (ptimeout.host, sleep 15, ...)
ppid_arg = ','.join(data)
if len(ppid_arg) == 0:
	sys.exit()

s = commands.getoutput('pgrep -P '+ppid_arg)
ppids = s.splitlines()
ppid_arg = ','.join(ppids)
s = commands.getoutput('ps ax -o pid,ppid,etime,command -p '+ppid_arg)
list = s.splitlines()
list.pop(0)
ppid_map = { }
idlers = { }
for line in list:
	fields = line.split()
	pid = fields.pop(0)
	ppid = fields.pop(0)
	time = fields.pop(0)
	command = ' '.join(fields)
	if command.count('ptimeout.host'):
		command = "building ("+time+")"
	elif command == 'sleep 15':
		command = "waiting for idle node"
		idlers[ppid] = ppid
	elif command.count('scripts/clean-chroot'):
		command = "cleaning up the node ("+time+")"
	elif command.count('scripts/claim-chroot'):
		command = "preparing node ("+time+")"
	elif command.count('tar --unlink'):
		command = "copying package ("+time+")"
	elif command.count('scp ') and command.count('.log '):
		command = "copying logs ("+time+")"
	else:
		command = command+" ("+time+")"
	if data.has_key(ppid):
		blob = data[ppid]
		blob['command'] = command
		ppid_map[pid] = ppid

# fill in sleeper's parent pid etimes
if len(idlers):
	ppid_arg = ','.join(idlers)
	s = commands.getoutput('ps ax -o pid,etime -p '+ppid_arg)
	lines = s.splitlines()
	lines.pop(0)
	for line in lines:
		fields = line.split()
		ppid = fields[0]
		time = fields[1]
		blob = data[ppid]
		blob['command'] = blob['command'] + ' ('+time+')'

# get list of sub-subprocesses (ssh is interesting here)
ssh_map = { }
ppid_arg = ','.join(ppid_map)
if len(ppid_arg) > 0:
	s = commands.getoutput('pgrep -P '+ppid_arg)
	ppids = s.splitlines()
	ppid_arg = ','.join(ppids)
	if len(ppid_arg) > 0:
		s = commands.getoutput('ps ax -o pid,ppid,comm -p '+ppid_arg)
		list = s.splitlines()
		list.pop(0)
		for line in list:
			fields = line.split()
			spid = fields[0]
			pid = fields[1]
			command = fields[2]
			if command != 'ssh':
				continue
			if ppid_map.has_key(pid):
				ssh_map[spid] = ppid_map[pid]

# get list of network sockets
s = commands.getoutput('sockstat -4 -c -p 22')
list = s.splitlines()
list.pop(0)
for line in list:
	line = line[20:]
	fields = line.split()
	spid = fields.pop(0)
	host, port = fields.pop(3).split(':')
	if port != '22':
		continue
	if ssh_map.has_key(spid):
		ppid = ssh_map[spid]
		if data.has_key(ppid):
			try:
				hostname, bork, bork = socket.gethostbyaddr(host)
			except socket.herror:
				hostname = host
			blob = data[ppid]
			blob['host'] = hostname
			if len(hostname) > hostwidth:
				hostwidth = len(hostname)

# format for output
output = [ ]
for pid in data:
	blob = data[pid]
	if not blob.has_key('host'):
		blob['host'] = ''
	if not blob.has_key('command'):
		blob['command'] = ''
	output.append(blob['arch'].ljust(archwidth + 2) + blob['branch'].ljust(branchwidth + 2) + blob['port'].ljust(portwidth + 2) + blob['host'].ljust(hostwidth + 2) + blob['command'])

# sort, output
output.sort()
print '\n'.join(output)
