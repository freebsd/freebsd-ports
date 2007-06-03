# New ports collection makefile for:	linux-mikmod
# Date created:				25 May 2007
# Whom:					Marcus von Appen <mva@sysfault.org>
#
# $FreeBSD$
#

PORTNAME=	mikmod
DISTVERSION=	3.1.6
CATEGORIES=	audio linux
DISTNAME=	${PORTNAME}-${PORTVERSION}-34

MAINTAINER=	mva@sysfault.org
COMMENT=	MikMod Sound Library (Linux version)

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
AUTOMATIC_PLIST=yes
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
MASTER_SITE_SRC_SUBDIR=	../extras/${LINUX_DIST_VER}/SRPMS
BRANDELF_DIRS=	usr/bin

.include <bsd.port.mk>
