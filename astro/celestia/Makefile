PORTNAME=	celestia
PORTVERSION=	1.6.1
PORTREVISION=	14
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/Celestia-source/${PORTVERSION}
PKGNAMESUFFIX=	-${CELESTIA_UI}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Scriptable space flight simulator for X11
WWW=		https://celestiaproject.space/

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png

USES=		compiler:c++11-lang gettext gl gmake jpeg libtool localbase:ldflags \
		lua:52 pkgconfig
USE_CXXSTD=	c++14
USE_GL=		gl
GNU_CONFIGURE=	yes
EXTRA_PATCHES=	${FILESDIR}/celestia-1.6.1-lua-5.2.patch:-p1 \
		${FILESDIR}/celestia-lua-52-fix.patch:-p1 \
		${FILESDIR}/celestia-1.6.1-gcc47.patch:-p1 \
		${FILESDIR}/celestia-1.6.1-gcc48.patch:-p1

CXXFLAGS+=	-fsigned-char	# fix text rendering (see Gentoo bug 316573)
LDFLAGS+=	-pthread

UI_LIST=	glut gtk gnome
CELESTIA_UI?=	glut
CONFLICTS_INSTALL=	${UI_LIST:S|^|celestia-|}

# Celestia provides different UI frontends; you should pick one that suits
# you best by setting CELESTIA_UI variable.  Possible values are:
#
# glut	Bare-boned minimal GLUT-based core with no toolbar or menu (this is
#	the default one);
# gtk	Full interface with minimal dependencies: adds menu, configuration
#	dialog, some other utilities;
#
.if ${CELESTIA_UI} == "glut"
CONFIGURE_ARGS+=	--with-glut
USE_GL+=	glut
LDFLAGS+=	-lGL
.elif ${CELESTIA_UI} == "gtk"
CONFIGURE_ARGS+=	--with-gtk
USES+=		gnome
USE_GNOME+=	gtk20
PLIST_FILES=	share/applications/celestia.desktop
.else
IGNORE=		requires one of the <${UI_LIST}> values for CELESTIA_UI
.endif

.if ${CELESTIA_UI} == "gtk"
USES+=		pathfix
LIB_DEPENDS+=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext \
		libtheora.so:multimedia/libtheora
STARTUP_NOTIFY=	true
PLIST_FILES+=	share/celestia/celestia-logo.png share/celestia/celestiaui.xml
.else
STARTUP_NOTIFY=	false
.endif

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -E '/fav(->|\.)fov/s|NULL|0.0|' \
		${WRKSRC}/src/celestia/celestiacore.cpp \
		${WRKSRC}/src/celestia/favorites.cpp
	@${REINPLACE_CMD} -e '280s,NULL,false,' \
		${WRKSRC}/src/celengine/parseobject.cpp
# Fix Lua discovery pkg-config(1) calls
	@${REINPLACE_CMD} -E 's|lua5\.?|lua-5.|' ${WRKSRC}/configure
# Remove controversial compiler options (respect our C[XX]FLAGS)
.for o in O2 ffast-math fexpensive-optimizations fomit-frame-pointer
	@${REINPLACE_CMD} -e 's|-${o}||g' ${WRKSRC}/configure
.endfor
# Allow add-ons to be placed inside user's home directory
	@${REINPLACE_CMD} -e '/^#/!s|"extras"|& "~/.celestia"|' \
		${WRKSRC}/celestia.cfg
# Inhibit installation of copies of GPL (lots of them; use LICENSE framework
# instead) and remove bogus argument from mv(1)
	@${REINPLACE_CMD} -e 's|COPYING||g ; s| -b|| ' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|=.*COPYING_\*)|=| ; \
		/KDE_DIST/s|COPYING_[^ ]* ||g' ${WRKSRC}/locale/Makefile.in
	@${REINPLACE_CMD} -e 's|kde_libs_htmldir|kde_htmldir|' \
		${WRKSRC}/src/celestia/kde/doc/celestia/Makefile.in

post-install:
# Technically, we should only install icon explicitly for GLUT UI, since
# correct icons are properly installed for other cases, but doing it here
# does not hurt and simplifies PLIST handling
	${INSTALL_DATA} ${WRKSRC}/src/celestia/gtk/data/celestia.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
