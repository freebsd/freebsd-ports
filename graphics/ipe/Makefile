PORTNAME=	ipe
DISTVERSION=	7.2.26
DISTVERSIONSUFFIX=	-src
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/otfried/old-ipe-releases/releases/download/v${DISTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Extensible vector graphics editor with LaTeX support
WWW=		https://ipe.otfried.org/

LICENSE=	GPLv3+

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2 \
		libgsl.so:math/gsl \
		libpng.so:graphics/png \
		libspiro.so:graphics/libspiro
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		compiler:c++11-lib gmake gnome jpeg lua:52 pkgconfig shebangfix qt:5 tex
USE_GNOME=	cairo
USE_LDCONFIG=	yes
USE_QT=		buildtools:build core gui qmake:build widgets
USE_TEX=	pdftex

SHEBANG_FILES=	${WRKSRC}/ipecurl/ipecurl.sh

MAKE_ENV=	DL_LIBS="" \
		INSTALL_DIR="${MKDIR}" \
		INSTALL_FILES="${INSTALL_DATA}" \
		INSTALL_SCRIPTS="${INSTALL_SCRIPT}" \
		INSTALL_PROGRAMS="${INSTALL_PROGRAM}" \
		INSTALL_ROOT="${STAGEDIR}" \
		IPEDOCDIR="${DOCSDIR}" \
		IPEMANDIR="${PREFIX}/share/man/man1" \
		IPEPREFIX="${PREFIX}" \
		JPEG_CFLAGS="-I${LOCALBASE}/include" \
		JPEG_LIBS="-L${LOCALBASE}/lib -ljpeg" \
		LUA_PACKAGE="lua-${LUA_VER}" \
		MOC="${MOC}" \
		IPE_NO_SPELLCHECK="1"

CPPFLAGS+=	-I${LOCALBASE}/${QT_INCDIR_REL} \
		-I${LOCALBASE}/include/cairo \
		-I${LUA_INCDIR} \
		-I${WRKSRC}/include \
		-I${WRKSRC}/ipecairo \
		-I${WRKSRC}/ipecanvas

DESKTOP_ENTRIES="Ipe" "" "ipe" "ipe" "" ""

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}/src

PLIST_SUB=	VERSION="${DISTVERSION}"
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|\([[:blank:]]\)=|\1?=|' ${WRKSRC}/config.mak
	@${REINPLACE_CMD} -e 's|<QWidget>|<QtWidgets/QWidget>|' \
		${WRKSRC}/ipeui/ipeui_common.h \
		${WRKSRC}/ipecanvas/ipepdfview_qt.h
	@${REINPLACE_CMD} -e 's|<QDialog>|<QtWidgets/QDialog>|; \
		s|<QGridLayout>|<QtWidgets/QGridLayout>|; \
		s|<QMenu>|<QtWidgets/QMenu>|; \
		s|<QApplication>|<QtWidgets/QApplication>|; \
		s|<QAction>|<QtWidgets/QAction>|' \
		${WRKSRC}/ipeui/ipeui_qt.h
	@${REINPLACE_CMD} -e 's|<QApplication>|<QtWidgets/QApplication>|; \
		s|<QCheckBox>|<QtWidgets/QCheckBox>|' \
		${WRKSRC}/ipeui/ipeui_qt.cpp
	@${REINPLACE_CMD} -e 's|<QListWidget>|<QtWidgets/QListWidget>|' \
		${WRKSRC}/ipecanvas/ipeselector_qt.h
	@${REINPLACE_CMD} -e 's|<QLabel>|<QtWidgets/QLabel>|; \
		s|<QTime>|<QtCore/QTime>|; \
		s|<QTimer>|<QtCore/QTimer>|' \
		${WRKSRC}/ipepresenter/timelabel_qt.h
	@${REINPLACE_CMD} -e 's|<QInputDialog>|<QtWidgets/QInputDialog>|' \
		${WRKSRC}/ipepresenter/timelabel_qt.cpp
	@${REINPLACE_CMD} -e 's|<QMainWindow>|<QtWidgets/QMainWindow>|; \
		s|<QPlainTextEdit>|<QtWidgets/QPlainTextEdit>|' \
		${WRKSRC}/ipepresenter/ipepresenter_qt.h

post-install:
	@${LN} -sf ${DATADIR}/${PORTVERSION}/ipe.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libipe*
.for filename in ipe6upgrade iperender ipeextract ipescript ipetoipe ipepresenter ipe
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${filename}
.endfor

.include <bsd.port.mk>
