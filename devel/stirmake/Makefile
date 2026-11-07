PORTNAME=	stirmake
DISTVERSION=	0.4.5
CATEGORIES=	devel
MASTER_SITES=	https://github.com/Aalto5G/stirmake/releases/download/v${DISTVERSION}/
DISTNAME=	stirmake-v${DISTVERSION}

MAINTAINER=	juha-matti.tilli@iki.fi
COMMENT=	Fast build tool with better support for recursion than make
WWW=		https://github.com/Aalto5G/stirmake/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE.md

MAKE_ENV+=	BYACC=false FLEX=false

WRKSRC_SUBDIR=	stirc

OPTIONS_DEFAULT=
OPTIONS_RADIO=		LUACONF
OPTIONS_RADIO_LUACONF=	LUA LUAJIT

LUAJIT_DESC=	Lua scripting language support via LuaJIT

LUAJIT_USES=	luajit
LUAJIT_MAKE_ENV=STIR_LUAINCS="-I${LUAJIT_INCDIR}" STIR_LUALIBS="-L${PREFIX}/lib -lluajit-5.1" STIR_WITH_LUA=1
LUA_USES=	lua
LUA_MAKE_ENV=	STIR_LUAINCS="-I${LUA_INCDIR}" STIR_LUALIBS="-L${LUA_LIBDIR} -llua-${LUA_VER}" STIR_WITH_LUA=1

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./bootstrapnomake.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stirmake ${STAGEDIR}${PREFIX}/bin
	${RLN} stirmake ${STAGEDIR}${PREFIX}/bin/smka
	${RLN} stirmake ${STAGEDIR}${PREFIX}/bin/smkp
	${RLN} stirmake ${STAGEDIR}${PREFIX}/bin/smkt

	${INSTALL_MAN} ${WRKSRC}/stirmake.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${RLN} stirmake.1.gz ${STAGEDIR}${PREFIX}/share/man/man1/smka.1.gz
	${RLN} stirmake.1.gz ${STAGEDIR}${PREFIX}/share/man/man1/smkp.1.gz
	${RLN} stirmake.1.gz ${STAGEDIR}${PREFIX}/share/man/man1/smkt.1.gz

do-test:
	cd ${WRKSRC}/autotest && ${SETENV} ${TEST_ENV} ./suite.sh

.include <bsd.port.mk>
