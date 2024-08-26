PORTNAME=	spotify-player
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.1
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

USES=		cargo ssl

USE_GITHUB=	yes
GH_ACCOUNT=	aome510

CARGO_CARGOTOML=	${WRKSRC}/spotify_player/Cargo.toml
CARGO_FEATURES=		--no-default-features
CARGO_INSTALL_PATH=	./spotify_player

PLIST_FILES=	bin/spotify_player
PORTDOCS=	README.md

OPTIONS_DEFINE=		CLIPBOARD DAEMON DBUS DOCS IMAGE LYRICS NOTIFY
OPTIONS_DEFAULT=	CLIPBOARD DBUS NOTIFY PORTAUDIO
OPTIONS_SINGLE=		BACKEND
OPTIONS_SINGLE_BACKEND=	PORTAUDIO PULSEAUDIO

CLIPBOARD_DESC=	Open Spotify links from clipboard
DAEMON_DESC=	Ability to launch as daemon
DBUS_DESC=	Media control via MPRIS D-Bus
IMAGE_DESC=	Terminal album art rendering
LYRICS_DESC=	Fetch lyrics for current track
NOTIFY_DESC=	Desktop notifications

CLIPBOARD_VARS=	CARGO_FEATURES+=clipboard

DAEMON_VARS=	CARGO_FEATURES+=daemon

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_VARS=		CARGO_FEATURES+=media-control

IMAGE_VARS=	CARGO_FEATURES+=image

LYRICS_VARS=	CARGO_FEATURES+=lyric-finder

NOTIFY_VARS=	CARGO_FEATURES+=notify

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_VARS=		CARGO_FEATURES+=portaudio-backend

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_VARS=	CARGO_FEATURES+=pulseaudio-backend

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/spotify_player

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
