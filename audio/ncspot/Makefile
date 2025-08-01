PORTNAME=	ncspot
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	audio

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Ncurses Spotify client
WWW=		https://github.com/hrkfdn/ncspot

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bindgen:devel/rust-bindgen-cli
LIB_DEPENDS=	libdbus-1.so:devel/dbus

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	hrkfdn

CARGO_FEATURES=	--no-default-features termion_backend

PLIST_FILES=	bin/ncspot
PORTDOCS=	README.md

OPTIONS_DEFINE=		CLIPBOARD DOCS MPRIS NOTIFY
OPTIONS_DEFAULT=	CLIPBOARD MPRIS NOTIFY PORTAUDIO
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	PORTAUDIO PULSEAUDIO

CLIPBOARD_DESC=	Support for accessing X11 clipboard
MPRIS_DESC=	D-Bus MPRIS support

CLIPBOARD_USES=		python:build xorg
CLIPBOARD_USE=		XORG=xcb
CLIPBOARD_BINARY_ALIAS=	python3=${PYTHON_CMD}
CLIPBOARD_VARS=		CARGO_FEATURES+=share_clipboard

MPRIS_VARS=	CARGO_FEATURES+=mpris

NOTIFY_VARS=	CARGO_FEATURES+=notify

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_VARS=		CARGO_FEATURES+=portaudio_backend

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_USES=	localbase:ldflags
PULSEAUDIO_VARS=	CARGO_FEATURES+=pulseaudio_backend

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
