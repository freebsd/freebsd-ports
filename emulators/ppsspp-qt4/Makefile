# $FreeBSD$

PORTREVISION=	0
PKGNAMESUFFIX=	-qt4

MASTERDIR=	${.CURDIR}/../ppsspp

OPTIONS_SLAVE=	QT4
OPTIONS_EXCLUDE=${OPTIONS_SINGLE_GUI}

# XXX Why OPTIONS_EXCLUDE doesn't trigger _OFF helpers?
do-install-QT4-on:	do-install-SDL-off

.include "${MASTERDIR}/Makefile"
