#! /bin/sh

set -e

usage() {
	echo "Usage: $0 <path>"
	echo "<path>    path to the executables"
}

test "$#" -eq 1 || ( usage && exit 1 )

set -x

PATH="$1:$PATH"

DBDIR=$( mktemp -d -t tmp.mongodb )

trap 'rm -rf "$DBDIR"' EXIT

# Trivial check if the binaries execute at all.
mongod --version
mongos --version
mongo --version

# Check if an empty database can be created.
mkdir "$DBDIR/db"
tail -F "$DBDIR/log" | ( grep -qFe "Waiting for connections" && kill $(cat "$DBDIR/pid") ) &
script -eF "$DBDIR/log" \
	timeout -s TERM -k 30s 60s \
	mongod --dbpath "$DBDIR/db" --pidfilepath "$DBDIR/pid"

echo "Test successful"
