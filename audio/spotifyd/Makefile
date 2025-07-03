PORTNAME=	spotifyd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
PORTREVISION=	3
CATEGORIES=	audio

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Spotify daemon
WWW=		https://github.com/Spotifyd/spotifyd

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libogg.so:audio/libogg

USES=		cargo ssl:build llvm
USE_GITHUB=	yes
GH_ACCOUNT=	Spotifyd
USE_RC_SUBR=	spotifyd

CARGO_FEATURES=	--no-default-features

PLIST_FILES=	bin/spotifyd \
		"@sample etc/spotifyd.conf.sample"
PORTDOCS=	README.md

OPTIONS_DEFINE=		ALSA DBUS DNS-SD DOCS PORTAUDIO PULSEAUDIO
OPTIONS_DEFAULT=	PORTAUDIO

DBUS_DESC=	D-Bus MPRIS support
DNS-SD_DESC=	Avahi mDNSS support

ALSA_LIB_DEPENDS=	libasound_module_pcm_oss.so:audio/alsa-plugins
ALSA_VARS=		CARGO_FEATURES+=alsa_backend

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_VARS=		CARGO_FEATURES+=dbus_mpris

DNS-SD_LIB_DEPENDS=	libdns_sd.so:net/avahi-libdns
DNS-SD_EXTRA_PATCHES=	${PATCHDIR}/extra-patch.Cargo.toml

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_VARS=		CARGO_FEATURES+=portaudio_backend

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_VARS=	CARGO_FEATURES+=pulseaudio_backend

post-patch:
	@${REINPLACE_CMD} 's,/etc/,${PREFIX}/etc/,g' ${WRKSRC}/src/config.rs

post-install:
	${INSTALL_DATA} ${FILESDIR}/spotifyd.conf ${STAGEDIR}${PREFIX}/etc/spotifyd.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
