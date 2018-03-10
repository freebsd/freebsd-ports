# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ada
PORTVERSION=	1.0			# made-up; no version info on GH
PORTREVISION=	2
CATEGORIES=	lang
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ada binding for Lua

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

BUILD_DEPENDS=	gprbuild:devel/gprbuild

USES=		ada lua
USE_GITHUB=	yes
GH_ACCOUNT=	AdaCore
GH_PROJECT=	ada-lua
GH_TAGNAME=	e008192

SUB_FILES=	lua.gpr
SUB_LIST=	LUA_VER=${LUA_VER}

PORTEXAMPLES=	example1 example2
EXDIRPREFIX=	${WRKSRC}/examples/example
REPLACEMENT=	"-L${LOCALBASE}/lib", "-Wl,-R,${LOCALBASE}/lib",\
		"-llua-${LUA_VER}"

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|with "Lua"|with "../../lua.gpr"|' \
		-e 's|"-L../..", "-llua"|${REPLACEMENT}|' \
		${EXDIRPREFIX}1/example1.gpr \
		${EXDIRPREFIX}2/example2.gpr

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		gprbuild -Plua --create-missing-dirs)

do-build-EXAMPLES-on:
	(cd ${WRKSRC}/examples/example1 && ${SETENV} ${MAKE_ENV} \
		gprbuild -Pexample1 --create-missing-dirs)
	(cd ${WRKSRC}/examples/example2 && ${SETENV} ${MAKE_ENV} \
		gprbuild -Pexample2 --create-missing-dirs)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/lua-ada \
		${STAGEDIR}${PREFIX}/lib/gnat \
		${STAGEDIR}${PREFIX}/include/lua-ada
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${PREFIX}/lib/lua-ada
	${INSTALL_DATA} ${WRKSRC}/lua.gpr ${STAGEDIR}${PREFIX}/lib/gnat
	${INSTALL_DATA} ${WRKSRC}/src/*.ad[bs] \
		${STAGEDIR}${PREFIX}/include/lua-ada

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/example1/bin \
		${STAGEDIR}${EXAMPLESDIR}/example2/bin
	${INSTALL_DATA} ${EXDIRPREFIX}1/example1.lua \
		${EXDIRPREFIX}1/src/main.adb \
		${STAGEDIR}${EXAMPLESDIR}/example1
	${INSTALL_PROGRAM} ${EXDIRPREFIX}1/obj/main \
		${STAGEDIR}${EXAMPLESDIR}/example1/bin/hello-lua
	${INSTALL_DATA} ${EXDIRPREFIX}2/example2.lua \
		${EXDIRPREFIX}2/src/main.adb \
		${STAGEDIR}${EXAMPLESDIR}/example2
	${INSTALL_PROGRAM} ${EXDIRPREFIX}2/obj/main \
		${STAGEDIR}${EXAMPLESDIR}/example2/bin/hello-function

.include <bsd.port.mk>
