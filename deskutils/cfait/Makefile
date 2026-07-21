PORTNAME=	cfait
DISTVERSION=	1.0.9
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	https://codeberg.org/trougnouf/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-source-v${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	stephan@lichtenauer.co.za
COMMENT=	Cfait is a powerful, fast and elegant task manager
WWW=		https://codeberg.org/trougnouf/cfait

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		cargo
CARGO_INSTALL_ARGS=	--bin cfait
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

OPTIONS_DEFINE=	DOCS GUI
OPTIONS_DEFAULT=	GUI
OPTIONS_SUB=	yes

GUI_DESC=	Build with X11/Wayland GUI
GUI_VARS=	CARGO_BUILD_ARGS=--features=gui

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

post-install-GUI-on:
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/release/cfait-gui ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/assets/cfait.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/assets/cfait.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/

.include <bsd.port.mk>
