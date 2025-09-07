PORTNAME=	schismtracker
DISTVERSION=	20250825
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Module tracker editor/player resembling impulse tracker
WWW=		https://schismtracker.org/ \
		https://github.com/schismtracker/schismtracker

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 armv7 i386 powerpc powerpc64 powerpc64le

LIB_DEPENDS=	libutf8proc.so:textproc/utf8proc

USES=			autoreconf compiler:c++11-lib desktop-file-utils \
			localbase pkgconfig python xorg
USE_GITHUB=		yes
USE_XORG=		x11 xext xv
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-sdl12

PLIST_FILES=	bin/schismtracker \
		share/applications/schism.desktop \
		share/man/man1/schismtracker.1.gz \
		share/pixmaps/schism-icon-128.png \
		share/pixmaps/schism-itf-icon-128.png

OPTIONS_DEFINE=		FLAC SDL
OPTIONS_DEFAULT=	FLAC SDL

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CONFIGURE_ON=	--enable-flac-linking \
			--with-flac

SDL_USES=		sdl
SDL_USE=		SDL=sdl2
SDL_CONFIGURE_ON=	--enable-sdl2-linking \
			--with-sdl2

post-patch:
	@${REINPLACE_CMD} -e "s|%%LAST_GIT_COMMIT%%|${DISTVERSION}|" \
		${WRKSRC}/configure.ac

post-install:
	${INSTALL_DATA} ${WRKSRC}/sys/fd.org/*.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/icons/schism-icon-128.png \
		${WRKSRC}/icons/schism-itf-icon-128.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
