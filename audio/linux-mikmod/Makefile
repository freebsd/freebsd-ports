# New ports collection makefile for:	linux-mikmod
# Date created:				25 May 2007
# Whom:					Marcus von Appen <mva@sysfault.org>
#
# $FreeBSD$
#

PORTNAME=	mikmod
DISTVERSION=	3.1.6
PORTREVISION=	2
CATEGORIES=	audio linux
DISTNAME=	${PORTNAME}-${PORTVERSION}-34

MAINTAINER=	mva@FreeBSD.org
COMMENT=	MikMod Sound Library (Linux version)

CONFLICTS=	linux-f8-mikmod-[0-9]* linux-f10-mikmod-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
AUTOMATIC_PLIST=yes
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
BRANDELF_DIRS=	usr/bin

.include <bsd.port.mk>
