# Created by: shurd
# $FreeBSD$

PORTNAME=	syncterm
PORTVERSION=	1.0
CATEGORIES=	comms
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	shurd@FreeBSD.org
COMMENT=	ANSI-BBS terminal which supports telnet, rlogin, and SSH

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/syncterm-${PORTVERSION}/src/syncterm
USES=		gmake perl5 tar:tgz
USE_PERL5=	build
MAKEFILE=	GNUmakefile
PLIST_FILES=	bin/syncterm \
		man/man1/syncterm.1.gz \
		share/applications/syncterm.desktop \
		share/icons/hicolor/64x64/apps/syncterm.png

NO_CCACHE=	yes
MAKE_JOBS_UNSAFE=	yes
MAKE_ARGS+=	WITHOUT_PORTAUDIO=yes
MAKE_ARGS+=	-C ${WRKSRC}
MAKE_ARGS+=	PREFIX="${PREFIX}"
MAKE_ARGS+=	INSTALL_EXE="${INSTALL_PROGRAM}"
MAKE_ARGS+=	RELEASE=1

OPTIONS_DEFINE=	X11 SDL
OPTIONS_DEFAULT=	X11 SDL

X11_USES=	xorg
X11_USE=	xorg=x11
X11_MAKE_ARGS_OFF=	NO_X=1

SDL_USE=	SDL=sdl
SDL_MAKE_ARGS=	USE_SDL=1
SDL_MAKE_ARGS_OFF=	WITHOUT_SDL=1

ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	does not configure except on i386 amd64

.include <bsd.port.mk>
