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

LIB_DEPENDS=	libxerces-c.so:${PORTSDIR}/textproc/xerces-c2 \
		libpng.so:${PORTSDIR}/graphics/png
BUILD_DEPENDS=	${LOCALBASE}/lib/libenet.a:${PORTSDIR}/net/enet

USES=		gettext gmake
USE_LUA=	5.1
LUA_COMPS=	lua toluaxx
USE_SDL=	image mixer sdl ttf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-cxxlua \
		--with-libintl-prefix="${LOCALBASE}"
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15 -I${LUA_INCDIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

SUB_FILES=	pkg-message

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_DEFAULT=DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=nls

post-extract:
	@${RM} -rf ${WRKSRC}/lib-src/lua \
		${WRKSRC}/lib-src/enet ${WRKSRC}/tools ${WRKSRC}/intl

post-patch:
	@${REINPLACE_CMD} -e '/Exec=/s,enigma,${PREFIX}/bin/enigma,g' \
		${WRKSRC}/etc/enigma.desktop

.include <bsd.port.mk>
