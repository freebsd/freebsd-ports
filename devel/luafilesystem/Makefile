# Created by: Kelly Hays <kelly.hays@jkhfamily.org>
# $FreeBSD$

PORTNAME=	luafilesystem
PORTVERSION=	1.6.2
CATEGORIES=	devel
MASTER_SITES=	GH
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	fiziologus@gmail.com
COMMENT=	Library to access directory structure and file attributes

LICENSE=	MIT

USES=		lua

USE_GITHUB=	yes
GH_ACCOUNT=	keplerproject
GH_PROGECT=	${PORTNAME}
GH_TAGNAME=	v${PORTVERSION:S/./_/g}
GH_COMMIT=	9557350

ALL_TARGET=	lib

PLIST_FILES=	%%LUA_MODLIBDIR%%/lfs.so
PORTDOCS=	*

MAKE_ARGS+=	INCS="-I${LUA_INCDIR}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e \
		"s|%%PREFIX%%|${PREFIX}| ; \
		s|%%MODLIBDIR%%|${LUA_MODLIBDIR}| ; \
		s|%%INCDIR%%|${LUA_INCDIR}|" ${WRKSRC}/config

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
	${CP} ${WRKSRC}/doc/us/* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
