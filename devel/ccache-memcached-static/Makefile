# $FreeBSD$

PKGNAMESUFFIX=	-memcached-static

MASTERDIR=	${.CURDIR}/../ccache

OPTIONS_SLAVE=	MEMCACHED STATIC

CONFLICTS_INSTALL=	ccache-[0-9]* ccache-memcached[0-9]* ccache-static[0-9]*

.include "${MASTERDIR}/Makefile"
