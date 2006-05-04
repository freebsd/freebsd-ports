# New ports collection makefile for:	celestia
# Date created:				2002-05-17
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	celestia
PORTVERSION=	1.4.1
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	celestia
PKGNAMESUFFIX=	-${CELESTIA_UI}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	Scriptable space flight simulator for X

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_GL=		yes
USE_GETTEXT=	yes
WANT_GNOME=	yes
USE_X_PREFIX=	yes

CONFIGURE_ARGS=	--program-prefix=""
CONFIGURE_ENV=	\
	LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib -lm ${PTHREAD_LIBS}" \
	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include ${PTHREAD_CFLAGS}"

UI_LIST=	glut gtk gnome
CELESTIA_UI?=	glut
CONFLICTS=	${UI_LIST:S|${CELESTIA_UI}||:S|^|celestia-|:S|$|-[0-9]*|} # lol

.if ${CELESTIA_UI} == "glut"
CONFIGURE_ARGS+=	--with-glut
LIB_DEPENDS+=	glut:${PORTSDIR}/graphics/libglut
.elif ${CELESTIA_UI} == "gtk"
CONFIGURE_ARGS+=	--with-gtk
USE_GNOME+=	gtk20
.elif ${CELESTIA_UI} == "gnome"
CONFIGURE_ARGS+=	--with-gnome
USE_GNOME+=	libgnomeui
GCONF_SCHEMAS=	celestia.schemas
PKGMESSAGE=	${PKGDIR}/pkg-message.gnome
.else
IGNORE=		invalid CELESTIA_UI value "${CELESTIA_UI}" -- valid values are ${UI_LIST}
.endif

.if ${CELESTIA_UI} == "gtk" || ${CELESTIA_UI} == "gnome"
USE_GNOME+=	gnomehack
LIB_DEPENDS+=	gtkglext-x11-1.0:${PORTSDIR}/x11-toolkits/gtkglext
STARTUP_NOTIFY=	true
PLIST_FILES+=	share/celestia/celestia-logo.png share/celestia/celestiaui.xml
.else
STARTUP_NOTIFY=	false
.endif

PORTDOCS=	AUTHORS CelestiaKeyAssignments.txt ChangeLog \
		KbdMouseJoyControls.txt README TODO TRANSLATORS \
		coding-standards.html devguide.txt

DESKTOP_ENTRIES="Celestia" \
		"Explore space" \
		"celestia.png" \
		"celestia" \
		"Application;Astronomy;Science;Education;" \
		${STARTUP_NOTIFY}

OPTIONS=	LUA "Lua support" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not compile on FreeBSD 4.x
.endif

.if defined(WITH_LUA)
LIB_DEPENDS+=	lua.5:${PORTSDIR}/lang/lua50
CONFIGURE_ARGS+=	--with-lua
.endif

pre-patch:
.for o in -O2 -Wall -ffast-math -fexpensive-optimizations -fomit-frame-pointer
	@${REINPLACE_CMD} -e 's|${o}||g' ${WRKSRC}/configure
.endfor
	@${REINPLACE_CMD} -e 's|COPYING||g' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/celestia/gtk/data/celestia.png \
		${PREFIX}/share/pixmaps
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
.if ${CELESTIA_UI} == "gnome"
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
