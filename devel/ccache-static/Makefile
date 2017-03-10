# $FreeBSD$

PKGNAMESUFFIX=	-static

MASTERDIR=	${.CURDIR}/../ccache

OPTIONS_SLAVE=	STATIC

CONFLICTS_INSTALL=	ccache-[0-9]* ccache-memcached[0-9]* ccache-memcached-static[0-9]*

.include "${MASTERDIR}/Makefile"
