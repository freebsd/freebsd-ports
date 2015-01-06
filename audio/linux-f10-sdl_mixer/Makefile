# Created by: bsam
# $FreeBSD$

PORTNAME=	sdl_mixer
PORTVERSION=	1.2.8
PORTREVISION=	1
CATEGORIES=	audio linux
MASTER_SITES=	LOCAL/ehaupt/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
DISTNAME=	SDL_mixer-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Sample multi-channel audio mixer library (Linux Fedora 10)

CONFLICTS=	linux-sdl_mixer-[0-9]* linux-f8-sdl_mixer-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	f10
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	sdl12 mikmod
LINUX_NAME=	SDL_mixer

RPMVERSION=	9.fc10
BRANDELF_FILES=	usr/bin/playmus usr/bin/playwave
USE_LDCONFIG=	yes

PLIST_FILES=	usr/bin/playmus usr/lib/libSDL_mixer-1.2.so.0 \
		usr/bin/playwave usr/lib/libSDL_mixer-1.2.so.0.2.6
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}
PORTDOCS=	CHANGES COPYING README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
