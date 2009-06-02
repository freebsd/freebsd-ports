# New ports collection makefile for:	audio/linux-f8-freealut
# Date created:				2008-04-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	freealut
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	audio linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	A free implementation of OpenAL's ALUT standard (Linux Fedora 8)

CONFLICTS=	linux-freealut-[0-9]* linux-f10-freealut-[0-9]*

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	openal
LINUX_DIST_VER=	8
RPMVERSION=	5.fc8
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386 amd64

PLIST_FILES=	usr/lib/libalut.so.0 usr/lib/libalut.so.0.1.0
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING ChangeLog README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
