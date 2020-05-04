# Created by: Sergey V. Dyatko <sergey.dyatko@gmail.com>
# $FreeBSD$

PORTNAME=	lua-gd
PORTVERSION=	2.0.33r2
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://files.luaforge.net/releases/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}forLua5.1/

MAINTAINER=	sergey.dyatko@gmail.com
COMMENT=	GD bindings for the Lua programming language

LICENSE=	MIT

LIB_DEPENDS=	libgd.so:graphics/gd

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		lua:51,module
CFLAGS+=	-I${LUA_INCDIR} -I${LOCALBASE}/include
LDFLAGS+=	-shared -L${LOCALBASE}/lib -lgd -L${LUA_LIBDIR} -llua-${LUA_VER} -lm
GDFEATURES=	`gdlib-config --features |sed -e "s/GD_/-DGD_/g"`

DOCSDIR=	${LUA_DOCSDIR}
EXAMPLESDIR=	${LUA_EXAMPLESDIR}

.include <bsd.port.options.mk>

CFLAGS_aarch64+=-fPIC
CFLAGS_amd64+=	-fPIC
CFLAGS_i386+=	-fPIC

do-build:
	${CC} -o ${WRKSRC}/gd.so ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} ${GDFEATURES} ${WRKSRC}/luagd.c

do-install:
	${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gd.so ${STAGEDIR}${LUA_MODLIBDIR}
	${SETENV} LUA_CPATH=${STAGEDIR}${LUA_MODLIBDIR}/?.so ${LUA_CMD} ${WRKSRC}/test_features.lua
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/ && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR}/
	@${ECHO_MSG} "===> Documentation installed in ${STAGEDIR}${DOCSDIR}"
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/demos && ${INSTALL_DATA} * ${STAGEDIR}${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${STAGEDIR}${EXAMPLESDIR}"
.endif

.include <bsd.port.mk>
