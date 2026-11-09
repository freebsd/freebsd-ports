PORTNAME=	gcin
PORTVERSION=	2.9.4
PORTREVISION=	1
CATEGORIES=	chinese textproc gnome
MASTER_SITES=	http://hyperrate.com/gcin-source/:main
DISTFILES=	gcin-${PORTVERSION}${EXTRACT_SUFX}
PATCH_SITES=	https://people.freebsd.org/~vanilla/distfiles/:patch
PATCHFILES=	diff.${PORTNAME}-${PORTVERSION}:patch

MAINTAINER=	vanilla@FreeBSD.org
COMMENT?=	Traditional Chinese input utility in X
WWW=		https://hyperrate.com/dir.php?eid=67

LICENSE?=	LGPL21

BUILD_GCIN_LIST?=	base
USES?=		cmake gnome pkgconfig tar:xz
.if ${BUILD_GCIN_LIST:Mbase} == "base"
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpng16.so:graphics/png

USES+=		shebangfix xorg

USE_GNOME=	gtk30
USE_XORG=	x11 xtst xext
USE_LDCONFIG=	${PREFIX}/lib/gcin
SHEBANG_FILES=	scripts/gcin-user-setup \
		scripts/gtab.append_prepare \
		scripts/html-browser \
		scripts/tsin-gtab-import \
		scripts/tsin-gtab-edit \
		scripts/utf8-edit
.endif

CMAKE_ARGS+=	-DGCIN_USE_I18N:BOOL=OFF \
		-DGCIN_USE_XIM:BOOL=OFF \
		-DGCIN_USE_TRAY:BOOL=OFF \
		-DGCIN_USE_GCB:BOOL=OFF \
		-DGCIN_USE_ANTHY:BOOL=OFF \
		-DGCIN_USE_CHEWING:BOOL=OFF \
		-DGCIN_USE_GUANYINMA:BOOL=OFF \
		-DGCIN_USE_INDICATOR:BOOL=OFF \
		-DGCIN_USE_GTK2_IM:BOOL=OFF \
		-DGCIN_USE_GTK3_IM:BOOL=OFF \
		-DGCIN_USE_GTK4_IM:BOOL=OFF \
		-DGCIN_USE_QT5:BOOL=OFF \
		-DGCIN_USE_QT6:BOOL=OFF

.if ${BUILD_GCIN_LIST:Mbase} == "base"
CMAKE_ARGS+=	-DGCIN_USE_XIM:BOOL=ON \
		-DGCIN_USE_TRAY:BOOL=ON \
		-DGCIN_USE_GCB:BOOL=ON
.elif ${BUILD_GCIN_LIST:Manthy} == "anthy"
CMAKE_ARGS+=	-DGCIN_USE_ANTHY:BOOL=ON
.elif ${BUILD_GCIN_LIST:Mchewing} == "chewing"
CMAKE_ARGS+=	-DGCIN_USE_CHEWING:BOOL=ON
.elif ${BUILD_GCIN_LIST:Mmcbopomofo} == "mcbopomofo"
CMAKE_ARGS+=	-DGCIN_USE_MCBOPOMOFO:BOOL=ON \
		-DGCIN_MCBOPOMOFO_SOURCE=${WRKSRC}/mcbopomofo-src
.elif ${BUILD_GCIN_LIST:Mguanyinma} == "guanyinma"
LICENSE=	MIT
CMAKE_ARGS+=	-DGCIN_USE_GUANYINMA:BOOL=ON \
		-DGCIN_GUANYINMA_SOURCE=${GYM_SRC} \
		"-DGCIN_CARGO_ARGS=--locked;--offline"
USES+=		cargo
.elif ${BUILD_GCIN_LIST:Mgtk2} == "gtk2"
CMAKE_ARGS+=	-DGCIN_USE_GTK2_IM:BOOL=ON
.elif ${BUILD_GCIN_LIST:Mgtk3} == "gtk3"
CMAKE_ARGS+=	-DGCIN_USE_GTK3_IM:BOOL=ON
.elif ${BUILD_GCIN_LIST:Mgtk4} == "gtk4"
CMAKE_ARGS+=	-DGCIN_USE_GTK4_IM:BOOL=ON
.elif ${BUILD_GCIN_LIST:Mqt5} == "qt5"
CMAKE_ARGS+=	-DGCIN_USE_QT5:BOOL=ON
USES+=		compiler:c++11-lang qt:5
.elif ${BUILD_GCIN_LIST:Mqt6} == "qt6"
CMAKE_ARGS+=	-DGCIN_USE_QT6:BOOL=ON
USES+=		compiler:c++11-lang qt:6
.endif

.include <bsd.port.mk>
