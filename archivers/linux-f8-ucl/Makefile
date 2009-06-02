# New ports collection makefile for:	archivers/linux-f8-ucl
# Date created:				2008-04-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=		ucl
PORTVERSION=		1.03
PORTREVISION=		1
CATEGORIES=		archivers linux
PKGNAMEPREFIX=		linux-f8-
DISTNAME=		${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=		emulation@FreeBSD.org
COMMENT=		UCL, a lossless data compression library (Linux Fedora 8)

CONFLICTS=		linux-ucl-[0-9]* linux-f10-ucl-[0-9]*

USE_LINUX_RPM=		yes
LINUX_DIST_VER=		8
RPMVERSION=		7.fc8
USE_LDCONFIG=		yes

PLIST_FILES=		usr/lib/libucl.so.1 usr/lib/libucl.so.1.0.0
DOCSDIR=		${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=		COPYING NEWS README THANKS TODO
DESCR=			${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
