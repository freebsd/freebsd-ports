# $FreeBSD$

PKGNAMESUFFIX=	-memcached

MASTERDIR=	${.CURDIR}/../ccache

OPTIONS_SLAVE=	MEMCACHED

CONFLICTS_INSTALL=	ccache-[0-9]* ccache-memcached-static[0-9]* ccache-static-[0-9]*

.include "${MASTERDIR}/Makefile"
