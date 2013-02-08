# Created by: Kelly Hays <kelly.hays@jkhfamily.org>
# $FreeBSD$

PORTNAME=	luafilesystem
PORTVERSION=	1.5.0
CATEGORIES=	devel
MASTER_SITES=	GH
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	fiziologus@gmail.com
COMMENT=	Library to access directory structure and file attributes

LICENSE=	MIT

USE_LUA=	5.1

USE_GITHUB=	yes
GH_ACCOUNT=	keplerproject
GH_PROGECT=	${PORTNAME}
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	8ff2013

ALL_TARGET=	lib

PLIST_FILES=	%%LUA_MODLIBDIR%%/lfs.so
PORTDOCS=	*

MAKE_ARGS+=	INCS="-I${LOCALBASE}/include/${LUA_SUBDIR}"

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e \
		"s|%%PREFIX%%|${PREFIX}| ; \
		s|%%MODLIBDIR%%|${LUA_MODLIBDIR}| ; \
		s|%%INCDIR%%|${LUA_INCDIR}|" ${WRKSRC}/config

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR} && \
	${CP} ${WRKSRC}/doc/us/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
