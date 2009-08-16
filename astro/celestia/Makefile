# New ports collection makefile for:	Celestia
# Date created:				2002-05-17
# Whom:					Trevor Johnson <trevor@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	celestia
PORTVERSION=	1.6.0
CATEGORIES=	astro
MASTER_SITES=	SF
PKGNAMESUFFIX=	-${CELESTIA_UI}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Scriptable space flight simulator for X

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_GL=		gl
USE_XORG=	x11 xt xext xmu xi
USE_GETTEXT=	yes
WANT_GNOME=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

UI_LIST=	glut gtk gnome
CELESTIA_UI?=	glut
CONFLICTS=	${UI_LIST:S|${CELESTIA_UI}||:S|^|celestia-|:S|$|-[0-9]*|}

.if ${CELESTIA_UI} == "glut"
CONFIGURE_ARGS+=	--with-glut
USE_GL+=	glut
.elif ${CELESTIA_UI} == "gtk"
CONFIGURE_ARGS+=	--with-gtk
USE_GNOME+=	gtk20
.elif ${CELESTIA_UI} == "gnome"
CONFIGURE_ARGS+=	--with-gnome
USE_GNOME+=	libgnomeui
GCONF_SCHEMAS=	celestia.schemas
.else
IGNORE=		requires one of the <${UI_LIST}> values for CELESTIA_UI
.endif

.if ${CELESTIA_UI} == "gtk" || ${CELESTIA_UI} == "gnome"
USE_GNOME+=	gnomehack
LIB_DEPENDS+=	gtkglext-x11-1.0:${PORTSDIR}/x11-toolkits/gtkglext \
		theora.0:${PORTSDIR}/multimedia/libtheora
STARTUP_NOTIFY=	true
PLIST_FILES+=	share/celestia/celestia-logo.png share/celestia/celestiaui.xml
.else
STARTUP_NOTIFY=	false
.endif

PORTDOCS=	AUTHORS ChangeLog README

DESKTOP_ENTRIES="Celestia" \
		"Explore space" \
		"celestia.png" \
		"celestia" \
		"Application;Astronomy;Education;Science;" \
		${STARTUP_NOTIFY}

USE_LUA=	5.0+
CONFIGURE_ARGS+=	--with-lua LUA_CFLAGS=-I${LUA_INCDIR} \
		LUA_LIBS=-L${LUA_LIBDIR} LUALIB_LIBS=-llua

pre-patch:
.for o in O2 ffast-math fexpensive-optimizations fomit-frame-pointer
	@${REINPLACE_CMD} -e 's|-${o}||g' ${WRKSRC}/configure
.endfor
# Inhibit installation of copies of GPL (lots of them!)
	@${REINPLACE_CMD} -e 's|COPYING||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|=.*COPYING_\*)|=| ; \
		/KDE_DIST/s|COPYING_[^ ]* ||g' ${WRKSRC}/locale/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/celestia/gtk/data/celestia.png \
		${PREFIX}/share/pixmaps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
