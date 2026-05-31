PORTNAME=	lua
DISTVERSION=	5.4.8
CATEGORIES=	lang
MASTER_SITES=	https://www.lua.org/ftp/
PKGNAMESUFFIX=	${LUA_VER_STR}

MAINTAINER=	andrew@tao11.riddles.org.uk
COMMENT=	Powerful, efficient, lightweight, embeddable scripting language
WWW=		https://www.lua.org/

LICENSE=	MIT

USES=		cpe lua:core,54
USE_LDCONFIG=	yes

# using the "bsd" target rather than "freebsd" saves patching out the
# assumption of using base libedit in order to make it configurable. "bsd"
# is "generic" plus the POSIX and DLOPEN options, plus -Wl,-E at link time;
# it doesn't set CC either, which makes it easier for us to control that too.
ALL_TARGET=bsd

LUA_LIB_STATIC=	liblua-${LUA_VER}.a
LUA_LIB_SHARED=	liblua-${LUA_VER}.so
LUA_PC_FILE=	lua-${LUA_VER}.pc

CFLAGS+=	-fPIC
# 2019-01-25: -pthread in LIBS is a work around for the following bug:
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=235211
LIBS+=		-pthread

WITHOUT_NO_STRICT_ALIASING=yes

MAKE_ARGS+=	CC="${CC}" \
		CMCFLAGS="" \
		MYCFLAGS="${CPPFLAGS} ${CFLAGS}" \
		MYLDFLAGS="${LDFLAGS}" \
		MYLIBS="${LIBS}" \
		LUA_T=${LUA_CMD} \
		LUAC_T=${LUAC_CMD} \
		LUA_A=${LUA_LIB_STATIC} \
		LUA_SO=${LUA_LIB_SHARED} \
		LUA_SONAME=${LUA_LIB_SHARED} \
		TO_BIN="${LUA_CMD} ${LUAC_CMD}" \
		TO_LIB="${LUA_LIB_SHARED} ${LUA_LIB_STATIC}" \
		INSTALL_TOP=${STAGEDIR}${PREFIX} \
		INSTALL_INC=${STAGEDIR}${LUA_INCDIR} \
		INSTALL_EXEC="${INSTALL_PROGRAM}"

# Source, destination, and filenames to copy for the DOCS option
# (automatically added to pkg-plist if DOCS is set)
# We override DOCSDIR to get a per-version subdir.
# We put the docs for Lua proper in a lua/ subdir of the version subdir
# so that ports for Lua modules can use the version subdir too without
# making a mess.
DOCSDIR=	${LUA_DOCSDIR}
BUILD_WRKDOC=	${WRKSRC}/doc

SUB_FILES=	${LUA_PC_FILE}
SUB_LIST=	version=${PORTVERSION} \
		includedir=${LUA_INCDIR} \
		libdir=${LUA_LIBDIR} \
		soname=lua-${LUA_VER}

BUILD_WRKSRC=	${WRKSRC}/src

PORTDOCS=	*

# Options

OPTIONS_DEFAULT=	LIBEDIT_DL

OPTIONS_GROUP=		DOCSGRP DEBUGGRP
OPTIONS_GROUP_DEBUGGRP=	ASSERT APICHECK
OPTIONS_GROUP_DOCSGRP=	DOCS

OPTIONS_SINGLE=		EDITGRP
OPTIONS_SINGLE_EDITGRP=	EDITNONE LIBEDIT_DL LIBEDIT READLINE

# Option descriptions

APICHECK_DESC=	Enable API checks
ASSERT_DESC=	Enable interpreter assertions
DEBUGGRP_DESC=	Debugging options

DOCSGRP_DESC=	Documentation options
DOCS_DESC=	Install language and API reference (HTML, ~400kB)

EDITGRP_DESC=	Interactive command-line editing
EDITNONE_DESC=	No command-line editing
LIBEDIT_DESC=	Use libedit (breaks lcurses)
LIBEDIT_DL_DESC=Use dynamically loaded libedit (recommended)
READLINE_DESC=	Use GNU Readline (breaks lcurses)

# Option implementations

APICHECK_CPPFLAGS=	-DLUA_USE_APICHECK
ASSERT_CPPFLAGS=	-DLUAI_ASSERT

# EDITNONE currently requires no settings

LIBEDIT_USES=		libedit
LIBEDIT_CPPFLAGS=	-DLUA_USE_READLINE
LIBEDIT_LIBS=		-ledit

LIBEDIT_DL_USES=	libedit
LIBEDIT_DL_CPPFLAGS=	-DLUA_USE_READLINE_DL
LIBEDIT_DL_EXTRA_PATCHES=${PATCHDIR}/extra-patch-libedit-dl

READLINE_USES=		readline
READLINE_CPPFLAGS=	-DLUA_USE_READLINE
READLINE_LIBS=		-lreadline

# end of option vars

post-patch:
	@${REINPLACE_CMD} -e "/LUA_ROOT/s,/usr/local,${LUA_PREFIX}," \
		${WRKSRC}/src/luaconf.h
	@${REINPLACE_CMD} -e "s|man/man|share/man/man|g" \
		${WRKSRC}/Makefile

post-patch-LIBEDIT-on:
	@${REINPLACE_CMD} -e "s,readline/,editline/,g ; \
		/history\.h/d" ${WRKSRC}/src/lua.c

post-patch-LIBEDIT_DL-on:
	@${REINPLACE_CMD} \
		-e "/^#def.*LUA_READLINE_LIBPATH/s,/usr/local,${LOCALBASE}," \
		${WRKSRC}/src/lua.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${LUA_LIB_SHARED}
	${MV} ${STAGEDIR}${PREFIX}/share/man/man1/lua.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/${LUA_CMD}.1
	${MV} ${STAGEDIR}${PREFIX}/share/man/man1/luac.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/${LUAC_CMD}.1
	${INSTALL_DATA} ${WRKDIR}/${LUA_PC_FILE} \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${BUILD_WRKDOC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} '-not -name *\.1')

.include <bsd.port.mk>
