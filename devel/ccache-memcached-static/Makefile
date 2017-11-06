# $FreeBSD$

PKGNAMESUFFIX=	-memcached-static

MASTERDIR=	${.CURDIR}/../ccache

OPTIONS_SLAVE=	MEMCACHED STATIC

CONFLICTS_INSTALL=	ccache-[0-9]* ccache-memcached[0-9]* ccache-static[0-9]*

BROKEN_powerpc64=	fails to configure: checking for memcached in -lmemcached... no

.include "${MASTERDIR}/Makefile"
