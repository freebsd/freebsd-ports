# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	synfigstudio
PORTVERSION=	1.0.2
PORTREVISION=	3
CATEGORIES=	graphics multimedia
MASTER_SITES=	SF/synfig/releases/${PORTVERSION}/source

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Vector-based 2D animation software package

LICENSE=	GPLv2+

BUILD_DEPENDS=	etl>=0.04.19_1:devel/etl
LIB_DEPENDS=	libsynfig.so:devel/synfig
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		compiler:c++11-lang desktop-file-utils gmake libtool pathfix \
		pkgconfig shared-mime-info
USE_CXXSTD=	c++11
USE_GNOME=	gtkmm30 intltool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-update-mimedb
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS JACK NLS
OPTIONS_SUB=	yes

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_ENABLE=	jack

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e \
		'/optimization_flags/s|CXXFLAGS=|#CXXFLAGS=| ; \
		 /optimization_flags/s|CFLAGS=|#CFLAGS=| ; \
		 /DATADIRNAME/s|lib|share|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|el_GR|el| ; \
		 s|ja_JP|ja| ; \
		 s|no_NO|no| ; \
		 s|pl_PL|pl| ; \
		 s|sk_SK|sk| ; \
		 s|sv_SE|sv|' \
		${WRKSRC}/po/LINGUAS
	@${REINPLACE_CMD} -e \
		's|^#include <sigc++/hide.h>$$|#include <sigc++/sigc++.h>| ; \
		 s|^#include <sigc++/object.h>$$|#include <sigc++/sigc++.h>| ; \
		 s|^#include <sigc++/retype.h>$$|#include <sigc++/sigc++.h>|' \
		${WRKSRC}/src/gui/canvasview.cpp \
		${WRKSRC}/src/gui/compview.cpp \
		${WRKSRC}/src/gui/docks/dock_children.cpp \
		${WRKSRC}/src/gui/docks/dock_curves.cpp \
		${WRKSRC}/src/gui/docks/dock_history.cpp \
		${WRKSRC}/src/gui/docks/dock_keyframes.cpp \
		${WRKSRC}/src/gui/docks/dock_layergroups.cpp \
		${WRKSRC}/src/gui/docks/dock_layers.cpp \
		${WRKSRC}/src/gui/docks/dock_metadata.cpp \
		${WRKSRC}/src/gui/docks/dock_params.cpp \
		${WRKSRC}/src/gui/docks/dock_timetrack.cpp \
		${WRKSRC}/src/gui/docks/dock_toolbox.cpp \
		${WRKSRC}/src/gui/docks/dockable.cpp \
		${WRKSRC}/src/gui/docks/dockdialog.cpp \
		${WRKSRC}/src/gui/docks/dockmanager.h \
		${WRKSRC}/src/gui/duck.h \
		${WRKSRC}/src/gui/duckmatic.cpp \
		${WRKSRC}/src/gui/duckmatic.h \
		${WRKSRC}/src/gui/instance.cpp \
		${WRKSRC}/src/gui/instance.h \
		${WRKSRC}/src/gui/states/state_stroke.h \
		${WRKSRC}/src/gui/states/state_zoom.cpp \
		${WRKSRC}/src/gui/widgets/widget_curves.cpp \
		${WRKSRC}/src/gui/workarea.cpp \
		${WRKSRC}/src/gui/workarearenderer/workarearenderer.h \
		${WRKSRC}/src/synfigapp/action_system.h \
		${WRKSRC}/src/synfigapp/canvasinterface.h \
		${WRKSRC}/src/synfigapp/instance.h \
		${WRKSRC}/src/synfigapp/main.h \
		${WRKSRC}/src/synfigapp/uimanager.h

pre-build:
# FIX LC_MESSAGES
	@${LN} -sf el_GR.po ${WRKSRC}/po/el.po
	@${LN} -sf ja_JP.po ${WRKSRC}/po/ja.po
	@${LN} -sf no_NO.po ${WRKSRC}/po/no.po
	@${LN} -sf pl_PL.po ${WRKSRC}/po/pl.po
	@${LN} -sf sk_SK.po ${WRKSRC}/po/sk.po
	@${LN} -sf sv_SE.po ${WRKSRC}/po/sv.po

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS ChangeLog INSTALL NEWS README TODO
	(cd ${WRKSRC} && ${INSTALL_DATA} ${doc} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
