PORTNAME=	schismtracker
DISTVERSION=	20240809
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Module tracker editor/player resembling impulse tracker
WWW=		https://schismtracker.org/ \
		https://github.com/schismtracker/schismtracker

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 armv7 i386 powerpc powerpc64 powerpc64le

LIB_DEPENDS=	libFLAC.so:audio/flac

USES=		autoreconf compiler:c++11-lib desktop-file-utils localbase \
		pkgconfig python sdl xorg
USE_GITHUB=	yes
USE_SDL=	sdl2
USE_XORG=	x11 xext xv
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/schismtracker \
		share/applications/schism.desktop \
		share/man/man1/schismtracker.1.gz \
		share/pixmaps/schism-icon-128.png \
		share/pixmaps/schism-itf-icon-128.png

post-install:
	${INSTALL_DATA} ${WRKSRC}/sys/fd.org/*.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/icons/schism-icon-128.png \
		${WRKSRC}/icons/schism-itf-icon-128.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
