PORTREVISION=	3
PKGNAMESUFFIX=	+ipv6

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IPv6 enabled cvs.  You can use IPv6 connection when using pserver

CONFLICTS_INSTALL=	cvs cvs-devel

OPTIONS_SLAVE=		IPV6
OPTIONS_EXCLUDE=	# empty

MASTERDIR=	${.CURDIR}/../cvs

.include "${MASTERDIR}/Makefile"
