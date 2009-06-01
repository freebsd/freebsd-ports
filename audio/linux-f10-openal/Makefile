# New ports collection makefile for:	audio/linux-f10-openal
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	openal
PORTVERSION=	0.0.9
CATEGORIES=	audio linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	A 3D positional spatialized sound library (Linux Fedora 10)

CONFLICTS=	linux-openal-[0-9]* linux-f8-openal-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	alsalib arts esound libaudiofile libvorbis sdl12
LINUX_DIST_VER=	10
RPMVERSION=	0.15.20060204cvs.fc9
USE_LDCONFIG=	yes

PLIST_FILES=	etc/openalrc usr/lib/libopenal.so.0 usr/lib/libopenal.so.0.0.0
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING ChangeLog NOTES README TODO
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
