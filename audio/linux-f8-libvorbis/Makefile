# New ports collection makefile for:	audio/linux-f8-libvorbis
# Date created:				2008-04-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	libvorbis
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	audio linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Audio compression codec library (Linux Fedora 8)

CONFLICTS=	linux-libvorbis-[0-9]* linux-f10-libvorbis-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	libogg
LINUX_DIST_VER=	8
RPMVERSION=	1.fc8
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libvorbis.so.0 usr/lib/libvorbis.so.0.4.0 \
		usr/lib/libvorbisenc.so.2 usr/lib/libvorbisenc.so.2.0.3 \
		usr/lib/libvorbisfile.so.3 usr/lib/libvorbisfile.so.3.2.0
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
