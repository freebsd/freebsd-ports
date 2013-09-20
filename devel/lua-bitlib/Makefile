# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bitlib
PORTVERSION=	24
CATEGORIES=	devel
MASTER_SITES=	http://luaforge.net/frs/download.php/2715/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	A tiny library for bitwise operations

USE_LUA=	5.0+

PLIST_FILES=	%%LUA_MODLIBDIR%%/bit.so

NO_STAGE=	yes
do-build:
	cd ${WRKSRC} && \
		${CC} -fPIC -shared -o bit.so lbitlib.c \
		${LUA_LIBDIR}/liblua.a -I${LUA_INCDIR} -lm

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bit.so ${LUA_MODLIBDIR}

.include <bsd.port.mk>
