# $FreeBSD$

PKGNAMESUFFIX=	-memcached

MASTERDIR=	${.CURDIR}/../ccache

OPTIONS_SLAVE=	MEMCACHED

CONFLICTS_INSTALL=	ccache-[0-9]*
NOCCACHE=	yes

.include "${MASTERDIR}/Makefile"
