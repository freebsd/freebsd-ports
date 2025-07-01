PORTNAME=	sidplayfp
DISTVERSION=	2.15.0
CATEGORIES=	audio
MASTER_SITES=	https://github.com/lib${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Console SID/MUS player using sidplayfp
WWW=		https://github.com/libsidplayfp/sidplayfp

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libstilview.so:audio/libsidplayfp

USES=		compiler:c++17-lang localbase:ldflags pkgconfig
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/sidplayfp \
		bin/stilview \
		share/man/man1/sidplayfp.1.gz \
		share/man/man1/stilview.1.gz \
		share/man/man5/sidplayfp.ini.5.gz

OPTIONS_DEFINE=		ALSA OUT123 PULSEAUDIO
OPTIONS_DEFAULT=	OUT123

OUT123_DESC=	Audio output support via mpg123's out123 library

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
OUT123_LIB_DEPENDS=	libout123.so:audio/mpg123
OUT123_CONFIGURE_WITH=	out123
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

pre-configure-ALSA-off:
	${REINPLACE_CMD} -e 's|alsa >= 1.0|alsa >= 9999.0|g' \
	    ${PATCH_WRKSRC}/configure

pre-configure-PULSEAUDIO-off:
	${REINPLACE_CMD} -e 's|libpulse-simple >= 1.0|libpulse-simple >= 9990.0|g' \
	    ${PATCH_WRKSRC}/configure

.include <bsd.port.mk>
