#!/bin/sh
#
# $FreeBSD$
#
# Maintenance shell script to vacuum and backup database
# Put this in /usr/local/etc/periodic/daily, and it will be run 
# every night
#
# Written by Palle Girgensohn <girgen@pingpong.net>
#
# In public domain, do what you like with it,
# and use it at your own risk... :)
#

# Define these variables in either /etc/periodic.conf or
# /etc/periodic.conf.local to override the default values.
#
# daily_pgsql_backup_enable="YES" # do backup of all databases
# daily_pgsql_backup_enable="foo bar db1 db2" # only do backup of a limited selection of databases
# daily_pgsql_vacuum_enable="YES" # do vacuum

daily_pgsql_vacuum_args="-z"
daily_pgsql_pgdump_args="-b -F c"
# backupdir is relative to ~pgsql home directory unless it begins with a slash:
daily_pgsql_backupdir="~pgsql/backups"
daily_pgsql_savedays="7"

# If there is a global system configuration file, suck it in.
#
if [ -r /etc/defaults/periodic.conf ]
then
    . /etc/defaults/periodic.conf
    source_periodic_confs
fi

# allow '~´ in dir name
eval backupdir=${daily_pgsql_backupdir}

rc=0

pgsql_backup() {
	# daily_pgsql_backupdir must be writeable by user pgsql
	# ~pgsql is just that under normal circumstances,
	# but this might not be where you want the backups...
	if [ ! -d ${backupdir} ] ; then 
	    echo Creating ${backupdir}
	    mkdir -m 700 ${backupdir}; chown pgsql ${backupdir}
	fi

	echo
	echo "PostgreSQL backups"

	# Protect the data
	umask 077
	rc=$?
	now=`date "+%Y-%m-%dT%H:%M:%S"`
	file=${daily_pgsql_backupdir}/pgglobals_${now}
	su -l pgsql -c "umask 077; pg_dumpall -g | gzip -9 > ${file}.gz"

	db=$1
	while shift; do
	    echo -n " $db"
	    file=${backupdir}/pgdump_${db}_${now}
	    su -l pgsql -c "umask 077; pg_dump ${daily_pgsql_pgdump_args} -f ${file} ${db}"
	    [ $? -gt 0 ] && rc=3
		db=$1
	done

	if [ $rc -gt 0 ]; then
	    echo
	    echo "Errors were reported during backup."
	fi

	# cleaning up old data
	find ${backupdir} \( -name 'pgdump_*' -o -name 'pgglobals_*' \) \
	    -a -mtime +${daily_pgsql_savedays} -delete
	echo
}

case "$daily_pgsql_backup_enable" in
    [Yy][Ee][Ss])
	dbnames=`su -l pgsql -c "umask 077; psql -q -t -A -d template1 -c SELECT\ datname\ FROM\ pg_database\ WHERE\ datname!=\'template0\'"`
	pgsql_backup $dbnames
	;;

	[Nn][Oo])
	;;

	"")
	;;

	*)
	pgsql_backup $daily_pgsql_backup_enable
	;;
esac

case "$daily_pgsql_vacuum_enable" in
    [Yy][Ee][Ss])

	echo
	echo "PostgreSQL vacuum"
	su -l pgsql -c "vacuumdb -a -q ${daily_pgsql_vacuum_args}"
	if [ $? -gt 0 ]
	then
	    echo
	    echo "Errors were reported during vacuum."
	    rc=3
	fi
	;;
esac

exit $rc
