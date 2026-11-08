PORTNAME=	omasnap
DISTVERSIONPREFIX=	v
DISTVERSION=	1.21.0
CATEGORIES=	graphics wayland

MAINTAINER=	jkh@FreeBSD.org
COMMENT=	Native Wayland screenshot and annotation overlay for Hyprland
WWW=		https://github.com/omacom/omasnap

LICENSE=	ISCL MIT OFL11
LICENSE_COMB=	multi
LICENSE_FILE_ISCL=	${WRKSRC}/assets/Lucide-ISC.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE
LICENSE_FILE_OFL11=	${WRKSRC}/assets/OFL.txt

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.37:graphics/wayland-protocols \
		wayland-scanner:graphics/wayland
LIB_DEPENDS=	libwayland-client.so:graphics/wayland
RUN_DEPENDS=	hyprctl:x11-wm/hyprland \
		tesseract:graphics/tesseract \
		wl-copy:x11/wl-clipboard

USES=		cmake:testing compiler:c++23-lang gl kde:6 pkgconfig qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	omacom
USE_GL=		opengl
USE_KDE=	layer-shell-qt
USE_QT=		base wayland:run

CMAKE_OFF=	BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING

PLIST_FILES=	bin/omasnap \
		share/applications/omasnap.desktop

PORTDOCS=	Inter-OFL.txt JetBrainsMono-OFL.txt Lucide-ISC.txt \
		Neucha-OFL.txt README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

post-install-DOCS-off:
	${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
