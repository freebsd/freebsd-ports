PORTNAME=	spotify-player
DISTVERSIONPREFIX=	v
DISTVERSION=	0.20.4
PORTREVISION=	4
CATEGORIES=	audio

MAINTAINER=	jfree@FreeBSD.org
COMMENT=	Command driven spotify player
WWW=		https://github.com/aome510/spotify-player

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	fails to build

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USES=		cargo llvm ssl

USE_GITHUB=	yes
GH_ACCOUNT=	aome510

CARGO_CARGOTOML=	${WRKSRC}/spotify_player/Cargo.toml
CARGO_FEATURES=		--no-default-features
CARGO_INSTALL_PATH=	./spotify_player

PLIST_FILES=	bin/spotify_player
PORTDOCS=	README.md

OPTIONS_DEFINE=		DAEMON \
			DBUS \
			DOCS \
			FUZZY_SEARCH \
			IMAGE \
			NOTIFY \
			STREAMING

OPTIONS_SINGLE=		BACKEND
OPTIONS_SINGLE_BACKEND=	PORTAUDIO PULSEAUDIO

OPTIONS_DEFAULT=	DBUS NOTIFY PORTAUDIO STREAMING

DAEMON_DESC=	Ability to launch as daemon
DBUS_DESC=	Media control via MPRIS D-Bus
FUZZY_SEARCH_DESC=	Approximate string matching
IMAGE_DESC=	Terminal album art rendering
NOTIFY_DESC=	Desktop notifications
STREAMING_DESC=	Play music directly from terminal

DAEMON_VARS=	CARGO_FEATURES+=daemon

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_VARS=		CARGO_FEATURES+=media-control

FUZZY_SEARCH_VARS=	CARGO_FEATURES+=fzf

IMAGE_VARS=	CARGO_FEATURES+=image

NOTIFY_VARS=	CARGO_FEATURES+=notify

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_VARS=		CARGO_FEATURES+=portaudio-backend

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_VARS=	CARGO_FEATURES+=pulseaudio-backend

STREAMING_VARS=	CARGO_FEATURES+=streaming

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
