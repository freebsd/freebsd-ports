# $FreeBSD$

PORTREVISION=	0
PKGNAMESUFFIX=	-qt5

MASTERDIR=	${.CURDIR}/../ppsspp

OPTIONS_SLAVE=	QT5

# XXX Why OPTIONS_EXCLUDE doesn't trigger _OFF helpers?
do-install-QT5-on:	do-install-SDL-off

.include "${MASTERDIR}/Makefile"
