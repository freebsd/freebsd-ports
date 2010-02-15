# New ports collection makefile for:	libgda4-java
# Date created:				10 Mar 2009
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION?=	0
CATEGORIES=	databases gnome
PKGNAMESUFFIX?=	-jdbc

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides Berkeley DB backend for the libgda4 library

MASTERDIR=	${.CURDIR}/../libgda4
BUILD_WRKSRC=	${WRKSRC}/providers/jdbc
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA4_SLAVE=	jdbc

.include "${MASTERDIR}/Makefile"
