# Created by: Kelly Hays <kelly.hays@jkhfamily.org>
# $FreeBSD$

PORTNAME=	luafilesystem
PORTVERSION=	1.6.3
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	fiziologus@gmail.com
COMMENT=	Library to access directory structure and file attributes

LICENSE=	MIT

USES?=		lua
USES+=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	keplerproject
GH_TAGNAME=	v_${PORTVERSION:S/./_/g}
GH_COMMIT=	8014725

ALL_TARGET=	lib

PLIST_FILES=	%%LUA_MODLIBDIR%%/lfs.so
PORTDOCS=	*

MAKE_ARGS+=	INCS="-I${LUA_INCDIR}"

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e \
		"s|%%PREFIX%%|${PREFIX}| ; \
		s|%%MODLIBDIR%%|${LUA_MODLIBDIR}| ; \
		s|%%INCDIR%%|${LUA_INCDIR}|" ${WRKSRC}/config

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
	${INSTALL_DATA} ${WRKSRC}/doc/us/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
