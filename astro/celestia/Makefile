# New ports collection makefile for:	Celestia
# Date created:				2002-05-17
# Whom:					Trevor Johnson <trevor@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	celestia
PORTVERSION=	1.4.1
PORTREVISION=	9
CATEGORIES=	astro
MASTER_SITES=	SF
PKGNAMESUFFIX=	-${CELESTIA_UI}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Scriptable space flight simulator for X

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_GL=		gl
USE_XORG=	x11 xt xext xmu xi
USE_GETTEXT=	yes
WANT_GNOME=	yes

CONFIGURE_ARGS=	--program-prefix=""
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -lm ${PTHREAD_LIBS}

UI_LIST=	glut gtk gnome
CELESTIA_UI?=	glut
CONFLICTS=	${UI_LIST:S|${CELESTIA_UI}||:S|^|celestia-|:S|$|-[0-9]*|} # lol

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

.if defined(WITH_LUA)
USE_LUA=	5.0
CONFIGURE_ARGS+=	--with-lua
CPPFLAGS+=	-I${LUA_INCDIR}
LDFLAGS+=	-L${LUA_LIBDIR}
.endif

pre-patch:
.for o in -O2 -Wall -ffast-math -fexpensive-optimizations -fomit-frame-pointer
	@${REINPLACE_CMD} -e 's|${o}||g' ${WRKSRC}/configure
.endfor
	@${REINPLACE_CMD} -e 's|COPYING||g' ${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/src/celestia/gtk/data/celestia.png \
		${PREFIX}/share/pixmaps
.for m in apollo cassini galileo gemini hubble iss marsglobalsurvr \
	marsodyssey mercury7 mir skylab
	${INSTALL_DATA} ${WRKSRC}/models/${m}.3ds \
		${PREFIX}/share/celestia/models
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
