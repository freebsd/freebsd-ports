#!/bin/sh
#
# $FreeBSD$
#
# Start or stop SETI@home, or set up working directory and register.
#

case $0 in
/*) rc_dir=${0%/*} ;;
 *) rc_dir=${PWD:-$(pwd)} ;;
esac
rc_file=${0##*/}
rc_path=${rc_dir}/${rc_file}
rc_arg=$1

# override these variables in ${PREFIX}/etc/rc.setiathome.conf
set -a
seti_wrkdir=/var/db/${rc_file%.sh}	# primary working directory
seti_std_args="-email -graphics"	# startup command line arguments
seti_reg_args=-login			# command line arguments to register
seti_proxy_server=			# HTTP proxy server (hostname:port)
seti_socks_server=			# SOCKS proxy server (hostname:port)
seti_socks_user=			# SOCKS proxy user name
seti_socks_passwd=			# SOCKS proxy password
seti_user=setiathome			# user name to run as
seti_group=${seti_user}			# group name to run as
seti_nice=15				# nice level to run at
seti_maxprocs=$(sysctl -n hw.ncpu)	# max. number of processes to start
seti_sleep_time=21600			# time to sleep between restarts
set +a

if ! PREFIX=$(expr ${rc_path} : "\(/.*\)/etc/rc\.d/${rc_file}\$"); then
	echo "${rc_file}: Cannot determine PREFIX." >&2
	echo "Please use the complete pathname." >&2
	exit 64
fi

rcconf_dir=${PREFIX}/etc
rcconf_file=rc.${rc_file%.sh}.conf
rcconf_path=${rcconf_dir}/${rcconf_file}

if [ -f ${rcconf_path} ]; then
	set -a
	. ${rcconf_path}
	set +a
fi

program_dir=${PREFIX}/sbin
program_file=${rc_file%.sh}
program_path=${program_dir}/${program_file}
export program_path

common_args="\
${seti_proxy_server:+-proxy} ${seti_proxy_server} \
${seti_socks_server:+-socks_server} ${seti_socks_server} \
${seti_socks_user:+-socks_user} ${seti_socks_user} \
${seti_socks_passwd:+-socks_passwd} ${seti_socks_passwd} \
${seti_nice:+-nice} ${seti_nice} \
"

program_args="${seti_std_args} ${common_args}"
export program_args
register_args="${seti_reg_args} ${common_args}"

wrapper_dir=${PREFIX}/libexec
wrapper_file=${rc_file%.sh}.bin
wrapper_path=${wrapper_dir}/${wrapper_file}

syslog_facility=daemon.err

i=${seti_maxprocs}
seti_wrksuff="."
while [ ${i} -gt 1 ]; do
	seti_wrksuff="${seti_wrksuff} ${i}"
	i=$((${i} - 1))
done
export seti_wrksuff

case "$rc_arg" in
start)
	if [ ! -x ${program_path} ]; then
		logger -sp ${syslog_facility} -t ${program_file} \
			"unable to start: ${program_path} is missing."
		exit 72
	fi
	if [ ! -x ${wrapper_path} ]; then
		logger -sp ${syslog_facility} -t ${wrapper_file} \
			"unable to start: ${wrapper_path} is missing."
		exit 72
	fi
	for i in ${seti_wrksuff}; do
		if [ ! -d ${seti_wrkdir}/${i} ]; then
			logger -sp ${syslog_facility} -t ${program_file} \
			"unable to start: ${seti_wrkdir}/${i} is missing."
			exit 72
		fi
		if [ ! -f ${seti_wrkdir}/${i}/user_info.sah ]; then
			logger -sp ${syslog_facility} -t ${program_file} \
			"unable to start: please log in to SETI@home first" \
			"(${seti_wrkdir}/${i}/user_info.sah is missing)."
			logger -sp ${syslog_facility} -t ${program_file} \
				"run \"$0 register\" to accomplish this."
			exit 72
		fi
	done
	if ps axo ucomm | egrep ${program_file}; then
		logger -sp ${syslog_facility} -t ${program_file} \
		"unable to start: ${program_file} is already running."
		exit 72
	fi
	su -fm ${seti_user} -c "exec ${wrapper_path} > /dev/null &"
	echo -n " SETI@home"
	;;

stop)
	pid_path=${seti_wrkdir}/shpid.sah
	if [ -f ${pid_path} ]; then
		pid=$(cat ${pid_path})
		[ -n "${pid}" ] && ps p ${pid} > /dev/null && kill ${pid}
		rm -f ${pid_path}
	fi
	for i in ${seti_wrksuff}; do
		pid_path=${seti_wrkdir}/${i}/pid.sah
		if [ -f ${pid_path} ]; then
			pid=$(cat ${pid_path})
			[ -n "${pid}" ] && ps p ${pid} > /dev/null && kill ${pid}
		fi
	done
	if [ ! -f ${seti_wrkdir}/pid.sah ]; then
		killall ${program_file} 2> /dev/null
	fi
	;;

gracefull)
	for i in ${seti_wrksuff}; do
		pid_path=${seti_wrkdir}/${i}/pid.sah
		stop_path=${seti_wrkdir}/${i}/stop_after_send.txt
		if [ -f ${pid_path} ]; then
			touch ${stop_path}
		fi
	done
	;;

restart)
	$0 stop
	$0 start
	;;

status)
	ps auxww | egrep ${program_file} | egrep -v "($0|egrep)"
	;;

register)
	if [ ! -x ${program_path} ]; then
		echo "${program_file}:" \
			"unable to register: ${program_path} is missing." >&2
		exit 72
	fi
	if pw group show "${seti_group}" 2>/dev/null; then
		echo "You already have a group \"${seti_group}\"," \
		     "so I will use it."
	elif pw groupadd ${seti_group} -h -; then
		echo "Added group \"${seti_group}\"."
	else
		echo "Adding group \"${seti_group}\" failed..."
		echo "Please create it, and try again."
		exit 1
	fi
	if pw user show "${seti_user}" 2>/dev/null; then
		echo "You already have a user \"${seti_user}\"," \
		     "so I will use it."
		if pw usermod ${seti_user} -d ${seti_wrkdir}; then
			echo "Changed home directory of \"${seti_user}\"" \
			     "to \"${seti_wrkdir}\""
		else
			echo "Changing home directory of \"${seti_user}\"" \
			     "to \"${setu_wrkdir}\" failed..."
			exit 1
		fi
	elif pw useradd ${seti_user} -g ${seti_group} -h - \
		-d ${seti_wrkdir} -s /sbin/nologin -c "SETI at home Daemon"; then
		echo "Added user \"${seti_user}\"."
	else
		echo "Adding user \"${seti_user}\" failed..."
		echo "Please create it, and try again."
		exit 1
	fi
	# Create or update primary working directory (in case the uid changed)
	mkdir -p ${seti_wrkdir} || exit
	chown -Rh ${seti_user}:${seti_group} ${seti_wrkdir} || exit
	chmod u=Xrw,g=Xr,o=Xr ${seti_wrkdir} || exit
	seti_dontlogin=no
	if [ -f ${seti_wrkdir}/user_info.sah ]; then
		echo    "      It seems you have already registered with" \
			"SETI@home.  Would you"
		echo -n "      like to repeat the procedure? [Y/n] "
		read a
		if [ "X${a}" = "Xn" -o "X${a}" = "XN" ]; then
			seti_dontlogin=yes
		fi
	fi
	# No need to register if we've already done so
	if [ "X${seti_dontlogin}" != "Xyes" ]; then
		su -fm ${seti_user} -c "\
			cd ${seti_wrkdir} && \
			exec ${program_path} ${register_args}"
	fi
	if [ ${seti_maxprocs} -gt 1 ]; then
		echo "      Updating additional working directories."
		i=${seti_maxprocs}
		while [ ${i} -gt 1 ]; do
			mkdir -p ${seti_wrkdir}/${i}
			chown ${seti_user} ${seti_wrkdir}/${i}
			chmod 755 ${seti_wrkdir}/${i}
			# Assume the user want's all processes to run
			# with the same registration
			rm -f ${seti_wrkdir}/${i}/user_info.sah
			ln -sf ../user_info.sah ${seti_wrkdir}/${i}
			i=$((${i} - 1))
		done
	fi
	;;		

*)
	echo "usage: ${rc_file} {start|stop|gracefull|restart|status|register}" >&2
	exit 64
	;;
esac
