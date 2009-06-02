# New ports collection makefile for:	audio/linux-f8-sdl_mixer
# Date created:				2008-04-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	sdl_mixer
PORTVERSION=	1.2.8
PORTREVISION=	1
CATEGORIES=	audio linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	A sample multi-channel audio mixer library (Linux Fedora 8)

CONFLICTS=	linux-sdl_mixer-[0-9]* linux-f10-sdl_mixer-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	sdl12
LINUX_NAME=	SDL_mixer
LINUX_DIST_VER=	8
RPMVERSION=	6.fc8
BRANDELF_FILES=	usr/bin/playmus usr/bin/playwave
USE_LDCONFIG=	yes

PLIST_FILES=	usr/bin/playmus usr/lib/libSDL_mixer-1.2.so.0 \
		usr/bin/playwave usr/lib/libSDL_mixer-1.2.so.0.2.6
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}
PORTDOCS=	CHANGES COPYING README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
