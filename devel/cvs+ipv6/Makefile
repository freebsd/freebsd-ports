# $FreeBSD$

PORTREVISION=	3
PKGNAMESUFFIX=	+ipv6

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IPv6 enabled cvs.  You can use IPv6 connection when using pserver

BROKEN=		unfetchable
DEPRECATED=	Unfetchable, unmaintained
EXPIRATION_DATE=	2019-10-16
CONFLICTS_INSTALL=	cvs-[12]* cvs-devel-[12]*

OPTIONS_SLAVE=		IPV6
OPTIONS_EXCLUDE=	# empty

MASTERDIR=	${.CURDIR}/../cvs

.include "${MASTERDIR}/Makefile"
