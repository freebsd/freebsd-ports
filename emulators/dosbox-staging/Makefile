PORTNAME=	dosbox-staging
DISTVERSIONPREFIX=	v
DISTVERSION=	0.76.0
PORTREVISION=	1
CATEGORIES=	emulators

MAINTAINER=	makc@FreeBSD.org
COMMENT=	DOS/x86 emulator based on DOSBox

LICENSE=	GPLv2

LIB_DEPENDS=	libopusfile.so:audio/opusfile \
		libpng.so:graphics/png

USES=		autoreconf compiler:c++14-lang gl pkgconfig sdl

USE_GL=		gl
USE_SDL=	sdl2 net2
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
LDFLAGS+=	-pthread

OPTIONS_DEFINE=	ALSA DOCS FLUIDSYNTH
OPTIONS_DEFAULT=	FLUIDSYNTH

ALSA_DESC=		ALSA midi support
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa-midi

FLUIDSYNTH_LIB_DEPENDS=		libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CONFIGURE_ENABLE=	fluidsynth

PORTDOCS=	NEWS README README.md

post-patch:
	@${REINPLACE_CMD} 's,/usr/share/doc/dosbox-staging,${DOCSDIR},' \
		${WRKSRC}/docs/dosbox.1
	@${REINPLACE_CMD} '/^Exec/s,dosbox,dosbox-staging,' \
		${WRKSRC}/contrib/linux/dosbox-staging.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dosbox ${STAGEDIR}${PREFIX}/bin/dosbox-staging
	${INSTALL_MAN} ${WRKSRC}/docs/dosbox.1 ${STAGEDIR}${PREFIX}/share/man/man1/dosbox-staging.1
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/linux/dosbox-staging.desktop ${STAGEDIR}${DESKTOPDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/contrib/icons/dosbox-staging.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
