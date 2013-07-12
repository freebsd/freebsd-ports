# Created by: Edwin Groothuis
# $FreeBSD$

PORTNAME=	enigma
PORTVERSION=	1.01
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	BERLIOS/enigma-game
DISTNAME=	${PORTNAME}-${PORTVERSION}-64bit

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Enigma is a reimplementation of Oxyd, a puzzle game

LIB_DEPENDS=	xerces-c:${PORTSDIR}/textproc/xerces-c2 \
		png15:${PORTSDIR}/graphics/png
BUILD_DEPENDS=	${LOCALBASE}/lib/libenet.a:${PORTSDIR}/net/enet

USE_GMAKE=	yes
USES=		gettext
USE_LUA=	5.1
LUA_COMPS=	lua toluaxx
USE_SDL=	image mixer sdl ttf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-cxxlua \
		--with-libintl-prefix="${LOCALBASE}"
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15 -I${LUA_INCDIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN6=		enigma.6

SUB_FILES=	pkg-message

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
USES+=		gettext
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-extract:
	@${RM} -rf ${WRKSRC}/lib-src/lua \
		${WRKSRC}/lib-src/enet ${WRKSRC}/tools ${WRKSRC}/intl

post-patch:
	@${REINPLACE_CMD} -e '/Exec=/s,enigma,${PREFIX}/bin/enigma,g' \
		${WRKSRC}/etc/enigma.desktop
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -E -e '/install-data-am/ s,install-(doc|index)DATA,,g' \
		${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|=.*|=|' ${WRKSRC}/doc/Makefile.in
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
