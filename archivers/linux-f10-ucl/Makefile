# New ports collection makefile for:	archivers/linux-f10-ucl
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=		ucl
PORTVERSION=		1.03
CATEGORIES=		archivers linux
PKGNAMEPREFIX=		linux-f10-
DISTNAME=		${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=		emulation@FreeBSD.org
COMMENT=		UCL, a lossless data compression library (Linux Fedora 10)

CONFLICTS=		linux-ucl-[0-9]* linux-f8-ucl-[0-9]*

USE_LINUX_RPM=		yes
LINUX_DIST_VER=		10
RPMVERSION=		8.fc9
USE_LDCONFIG=		yes

PLIST_FILES=		usr/lib/libucl.so.1 usr/lib/libucl.so.1.0.0
DOCSDIR=		${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=		COPYING NEWS README THANKS TODO
DESCR=			${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
