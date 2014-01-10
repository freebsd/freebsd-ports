# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bitlib
PORTVERSION=	24
CATEGORIES=	devel
MASTER_SITES=	http://luaforge.net/frs/download.php/2715/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Tiny library for bitwise operations

USES=		lua

PLIST_FILES=	%%LUA_MODLIBDIR%%/bit.so

do-build:
	cd ${WRKSRC} && \
		${CC} -fPIC -shared -o bit.so lbitlib.c \
		-I${LUA_INCDIR} -lm

do-install:
	@${MKDIR}  ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bit.so ${STAGEDIR}${LUA_MODLIBDIR}

.include <bsd.port.mk>
