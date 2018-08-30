# Created by: GreenDog <fiziologus@gmail.com>
# $FreeBSD$

PORTNAME=	lua
DISTVERSION=	5.3.5
CATEGORIES=	lang
MASTER_SITES=	https://www.lua.org/ftp/
PKGNAMESUFFIX=	53

MAINTAINER=	russ.haley@gmail.com
COMMENT=	Powerful, efficient, lightweight, embeddable scripting language

LICENSE=	MIT

LUA_VER=	5.3
USE_LDCONFIG=	yes

# Overriding __MAKE_CONF makes sure that we don't re-parse
# /etc/make.conf during do-build, which would jeopardize the build
# if, for instance, the user set CFLAGS=mumble
# NOTE: /etc/make.conf is read BEFORE Makefile, so we already
# have its settings when we get here.
# See http://wiki.freebsd.org/MatthiasAndree/LuaLessonsLearnt
MAKE_ARGS=	__MAKE_CONF=${NONEXISTENT}

BUILD_WRKSRC=	${WRKSRC}/src

# Source, destination, and filenames to copy for the DOCS option
# (automatically added to pkg-plist if DOCS is set)
# We override DOCSDIR to get a per-version subdir.
# We put the docs for Lua proper in a lua/ subdir of the version subdir
# so that ports for Lua modules can use the version subdir too without
# making a mess.
DOCSDIR=	${PREFIX}/share/doc/lua${PKGNAMESUFFIX}/lua
PORTDOCS=	*
BUILD_WRKDOC=	${WRKSRC}/doc

LUA_PREFIX=	${PREFIX}

# 2018-03-17: AG - These should match lua.mk, but we can't include that here
LUA_CMD=	lua${PKGNAMESUFFIX}
LUAC_CMD=	luac${PKGNAMESUFFIX}
LUA_INCDIR=	${LUA_PREFIX}/include/lua${PKGNAMESUFFIX}
LUA_LIBDIR=	${LUA_PREFIX}/lib

LUA_LIB_STATIC=	liblua-${LUA_VER}.a
LUA_LIB_SHARED=	liblua-${LUA_VER}.so
LUA_PC_FILE=	lua-${LUA_VER}.pc

# using the "bsd" target rather than "freebsd" saves patching out the
# assumption of using base libedit in order to make it configurable. "bsd"
# is "generic" plus the POSIX and DLOPEN options, plus -Wl,-E at link time;
# it doesn't set CC either, which makes it easier for us to control that too.
ALL_TARGET=bsd

# Options

OPTIONS_DEFAULT=LIBEDIT_DL

OPTIONS_GROUP=	DOCSGRP DEBUGGRP
OPTIONS_SINGLE=	EDITGRP

OPTIONS_GROUP_DOCSGRP=	DOCS
OPTIONS_GROUP_DEBUGGRP=	ASSERT APICHECK

OPTIONS_SINGLE_EDITGRP=	EDITNONE LIBEDIT_DL LIBEDIT READLINE

# Option descriptions

DEBUGGRP_DESC=	Debugging options
ASSERT_DESC=	Enable interpreter assertions
APICHECK_DESC=	Enable API checks

DOCSGRP_DESC=	Documentation options
DOCS_DESC=	Install language and API reference (HTML, ~400kB)

EDITGRP_DESC=	Interactive command-line editing
EDITNONE_DESC=	No command-line editing
LIBEDIT_DL_DESC=Use dynamically loaded libedit (recommended)
LIBEDIT_DESC=	Use libedit (breaks lcurses)
READLINE_DESC=	Use GNU Readline (breaks lcurses)

# Option implementations

ASSERT_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-assert

APICHECK_CPPFLAGS=	-DLUA_USE_APICHECK

# EDITNONE currently requires no settings

LIBEDIT_DL_USES=	libedit
LIBEDIT_DL_CPPFLAGS=	-DLUA_USE_READLINE_DL

LIBEDIT_USES=		libedit
LIBEDIT_CPPFLAGS=	-DLUA_USE_READLINE
LIBEDIT_LIBS=		-ledit

READLINE_USES=		readline
READLINE_CPPFLAGS=	-DLUA_USE_READLINE
READLINE_LIBS=		-lreadline

# end of option vars

CFLAGS+=	-fPIC

WITHOUT_NO_STRICT_ALIASING=yes

MAKE_ARGS+=	CC="${CC}" \
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

SUB_FILES=	${LUA_PC_FILE}
SUB_LIST=	version=${PORTVERSION} \
		includedir=${LUA_INCDIR} \
		libdir=${LUA_LIBDIR} \
		soname=lua-${LUA_VER}

post-patch:
	@${REINPLACE_CMD} -e "/LUA_ROOT/s,/usr/local,${LUA_PREFIX}," \
		${WRKSRC}/src/luaconf.h

post-patch-LIBEDIT-on:
	@${REINPLACE_CMD} -e "s,readline/,editline/,g ; \
		/history\.h/d" ${WRKSRC}/src/lua.c

post-patch-LIBEDIT_DL-on:
	@${REINPLACE_CMD} \
		-e "/^#def.*LUA_READLINE_LIBPATH/s,/usr/local,${LOCALBASE}," \
		${WRKSRC}/src/lua.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${LUA_LIB_SHARED}
	${MV} ${STAGEDIR}${PREFIX}/man/man1/lua.1 \
		${STAGEDIR}${PREFIX}/man/man1/${LUA_CMD}.1
	${MV} ${STAGEDIR}${PREFIX}/man/man1/luac.1 \
		${STAGEDIR}${PREFIX}/man/man1/${LUAC_CMD}.1
	${INSTALL_DATA} ${WRKDIR}/${LUA_PC_FILE} \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${BUILD_WRKDOC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} '-not -name *\.1')

.include <bsd.port.mk>
