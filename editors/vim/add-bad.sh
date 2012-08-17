:
# $FreeBSD$

usage() {
	echo 'usage: ${0##*/} <bad patch #s to add to ${BADPATCHES}>'
	exit 1
}
if [ $# -lt 1 ]; then
	usage
fi

sed -i '' "s/^BADPATCHES=.*$/& $*/" Makefile
