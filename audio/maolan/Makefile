PORTNAME=	maolan
DISTVERSION=	0.2.4
CATEGORIES=	audio

MAINTAINER=	meka@tilda.center
COMMENT=	Rust digital audio workstation
WWW=		https://maolan.github.io

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le

LIB_DEPENDS=	libjack.so:audio/jack

USES=		cargo localbase:ldflags pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	maolan

USE_XORG=	x11

CARGO_BUILD_ARGS+=	--workspace
CARGO_INSTALL_PATH=	. plugin-host
CARGO_TEST_AFTER_ARGS=	--skip \
			gui::tests::session_save_and_load_roundtrip_preserves_plugin_positions

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/assets/desktop/maolan-bsd.desktop \
		${STAGEDIR}${PREFIX}/share/applications/maolan.desktop
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/assets/images/maolan.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps

.include <bsd.port.mk>
