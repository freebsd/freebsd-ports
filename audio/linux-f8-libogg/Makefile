# New ports collection makefile for:	audio/linux-f8-libogg
# Date created:				2008-04-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	libogg
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	audio linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Ogg bitstream library (Linux Fedora 8)

CONFLICTS=	linux-libogg-[0-9]* linux-f10-libogg-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	8
RPMVERSION=	5.fc8
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libogg.so.0 usr/lib/libogg.so.0.5.3
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS CHANGES COPYING README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
