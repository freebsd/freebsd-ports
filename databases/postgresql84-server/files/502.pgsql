#!/bin/sh
#
# $Id: 502.pgsql.in,v 1.17 2001/10/29 10:12:32 henrik Exp $
#
# Maintenance shell script to vacuum and backup database
# Put this in /usr/local/etc/periodic/daily, and it will be run 
# every night
#
# Written by Palle Girgensohn <girgen@partitur.se>
#
# In public domain, do what you like with it,
# and use it at your own risk... :)
#

DIR=`dirname $0`
progname=`basename $0`
PRG=`cd $DIR; pwd `/$progname

# Run as user pgsql
if [ `id -un` != pgsql ]; then
    su -l pgsql -c ${PRG}
    exit 0
fi

# PGBACKUPDIR must be writeable by user pgsql
# ~pgsql is just that under normal circumstances,
# but this might not be where you want the backups...
PGBACKUPDIR=${HOME}/backups
if [ ! -d ${PGBACKUPDIR} ] ; then 
    echo Creating ${PGBACKUPDIR}
    mkdir ${PGBACKUPDIR}
    chmod 700 ${PGBACKUPDIR}
fi

PGLOGDIR=/var/log/pgsql
PGDIR=`cd ${PGDATA}/../ && pwd`

GZIP=/usr/bin/bzip2
GZIPEXT=bz2

echo
echo "PostgreSQL maintenance..."

# Protect the data
umask 077

dbname=`${PGBINDIR}/psql -q -t -A -d template1 -c "SELECT datname FROM pg_database WHERE datname != 'template0'"`

rc=0

echo -n "ALL"
PGERRALL=/tmp/PGERRALL.$$

${PGBINDIR}/pg_dumpall 2> $PGERRALL | ${GZIP} > ${PGBACKUPDIR}/pgdumpall_`date "+%Y%m%d"`.${GZIPEXT}

for i in ${dbname}; do
    echo -n " $i"
    ${PGBINDIR}/pg_dump $i 2>> $PGERRALL | ${GZIP} > ${PGBACKUPDIR}/pgdump_${i}_`date "+%Y%m%d"`.${GZIPEXT}
    ${PGBINDIR}/vacuumdb --quiet  --analyze $i || rc=3
done

if [ -s "${PGERRALL}" ]
then
    echo
    echo 'Something went wrong!'
    echo
    echo `cat ${PGERRALL}`
    rc=3
fi
rm ${PGERRALL}

echo

find ${PGBACKUPDIR} \( -name 'pgdump_*'.${GZIPEXT} -o -name 'pgdumpall_*'.${GZIPEXT} \) \
		    -a -atime +7 -delete
exit $rc
