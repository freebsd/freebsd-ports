PORTNAME=	vban
DISTVERSION=	g20201011
PORTREVISION=	1
CATEGORIES=	audio
PKGNAMESUFFIX=	-tools

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Command-line VBAN (audio over UDP protocol) tools

LICENSE=	GPLv3+

USES=		autoreconf localbase
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	quiniouben
GH_TAGNAME=	4f69e5a

PLIST_FILES=	bin/vban_emitter bin/vban_receptor bin/vban_sendtext
PORTDOCS=	README.md

PORTSCOUT=	skipv:2.1.0	# old tag from Oct 4 2018

OPTIONS_DEFINE=	DOCS
OPTIONS_MULTI=	BACKEND
OPTIONS_MULTI_BACKEND=ALSA JACK PULSEAUDIO
OPTIONS_DEFAULT=	ALSA JACK

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_OFF=	--disable-alsa

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_OFF=	--disable-jack

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=	--disable-pulseaudio

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
