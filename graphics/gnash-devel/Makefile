# New ports collection makefile for:	gnash
# Date created:				12 Jan 2006
# Whom:					Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	gnash
PORTVERSION=	0.7
CATEGORIES=	graphics
MASTER_SITES=	http://www.gnu.org/software/gnash/releases/
DISTNAME=	${PORTNAME}-20051226

MAINTAINER=	amdmi3@mail.ru
COMMENT=	GNU Flash movie player

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_X_PREFIX=	yes
USE_GNOME=	gnomehier
USE_SDL=	sdl mixer
USE_BZIP2=	yes
USE_GL=		yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
#INSTALLS_OMF=	yes
USE_GCC=	3.4+

WRKSRC=		${WRKDIR}/${PORTNAME}-0.7

CPPFLAGS=	`${SDL_CONFIG} --cflags` -I${X11BASE}/include
LDFLAGS=	`${SDL_CONFIG} --libs` -L${X11BASE}/lib -Wl,--rpath,${PREFIX}/lib/gnash

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--program-prefix=''

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib %%PREFIX%%/lib/gnash

MAN1=		gnash.1

# As the project was just recently announced, firefox plugin doesn't work
# correctly yet. You can still try it with specifying WITH_FIREFOX=yes as
# make parameter - feel free to mail reports (preferrably of success) and
# your ideas to port maintainer.
# See also http://lists.gnu.org/archive/html/gnash/

OPTIONS=	XML "Enable support for xml and xmlsocket" off
#		FIREFOX "Build firefox plugin" off

.include <bsd.port.pre.mk>

.if defined(WITH_FIREFOX)
BUILD_DEPENDS+=		${X11BASE}/bin/firefox-config:${PORTSDIR}/www/firefox
CONFIGURE_ARGS+=	--enable-plugin
CPPFLAGS+=		`firefox-config --cflags`
LDFLAGS+=		`firefox-config --libs`
PLIST_SUB=		PLUGIN:=""
.else
CONFIGURE_ARGS+=	--disable-reader
PLIST_SUB=		PLUGIN:="@comment "
.endif

.if defined(WITH_XML)
BUILD_DEPENDS+=		${LOCALBASE}/bin/xml2-config:${PORTSDIR}/textproc/libxml2
CPPFLAGS+=		`xml2-config --cflags`
LDFLAGS+=		`xml2-config --libs`
.else
CONFIGURE_ARGS+=	--disable-xml
.endif

post-extract:
	@${FIND} ${WRKSRC} -name "*.cpp" -o -name "*.h" | \
		${XARGS} ${REINPLACE_CMD} -e "s|$$(${PRINTF} '\r')||g"

post-patch:
	@${REINPLACE_CMD} -e '/INCLUDES/ s|$$(srcdir)||' ${WRKSRC}/libgeometry/Makefile.in ${WRKSRC}/libbase/Makefile.in
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/libbase/dlmalloc.c ${WRKSRC}/libbase/dlmalloc.h
	@${REINPLACE_CMD} -e '/APPLE_CC/ s|^.*$$|#if 0|' ${WRKSRC}/libbase/utility.cpp
	@${REINPLACE_CMD} -e '/cd doc/ s|^.*$$|	@true|; /DIRS/ s/ doc//' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^include_HEADERS/ s|^|#|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/FIREFOX_PLUGINS=.*FIREFOX_LIBS/ s|^.*$$|FIREFOX_PLUGINS=${X11BASE}/lib/browser_plugins|' ${WRKSRC}/configure
.if !defined(WITH_FIREFOX)
	@${REINPLACE_CMD} -e 's|firefox-config|firefox-config1|g' ${WRKSRC}/configure
.endif

.if defined(WITH_FIREFOX)
pre-install:
	${MKDIR} ${PREFIX}/lib/browser_plugins
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/C/gnash.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/gnome/omf/gnash
	${INSTALL_DATA} ${WRKSRC}/doc/C/gnash.omf ${PREFIX}/share/gnome/omf/gnash
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/images
.for i in gnash.html gnash.pdf gnash.xml legal.xml
	${INSTALL_DATA} ${WRKSRC}/doc/C/${i} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/C/images/* ${DOCSDIR}/images
.endif

.include <bsd.port.post.mk>
