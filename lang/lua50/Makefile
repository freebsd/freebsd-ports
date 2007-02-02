# New ports collection makefile for: 	lua
# Date created:				27 June 1999
# Whom:					Richard Kiss <him@richardkiss.com>
#
# $FreeBSD$
#

PORTNAME=	lua
PORTVERSION=	5.0.2
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	http://www.lua.org/ftp/ \
		ftp://ftp.tecgraf.puc-rio.br/pub/lua/ \
		ftp://csg.uwaterloo.ca/pub/lhf/lua/ \
		ftp://ftp.ntua.gr/pub/lang/lua/ \
		ftp://ftp.uni-trier.de/pub/languages/lua/ \
		ftp://ftp.gwdg.de/pub/languages/lua/

MAINTAINER=	him@richardkiss.com
COMMENT=	Small, compilable scripting language providing easy access to C code

USE_LDCONFIG=	yes
USE_LUA=	5.0
LUA_COMPS=	# only define variables
ALL_TARGET=	all so

MAN1=		lua-${LUA_VER}.1 luac-${LUA_VER}.1
DOCSDIR=	${PREFIX}/share/doc/${LUA_SUBDIR}
LATEST_LINK=	${LUA_SUBDIR}

LUA_BIN=	lua luac
LUA_LIB=	lua lualib
LUA_MAN=	${LUA_BIN:S/$/.1/}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|^(MYCFLAGS=).*|\1 ${CFLAGS}|; \
		 s|^(LOADLIB=).*|\1 -DUSE_DLOPEN=1|; \
		 s|^(CC=).*|\1 ${CC}|; \
		 s|^#(USERCONF.*READLINE.*)|\1|; \
		 s|^(EXTRA_LIBS=).*|\1 -lm -lreadline -lhistory -lncurses|; \
		 s|^(V=[[:digit:]])\.0|\1|' \
		${WRKSRC}/config
	@${REINPLACE_CMD} -Ee 's|(ld -o lib/(liblua(lib)?)\.so\.\$$V)|\1 -soname=\2-${LUA_VER}.so.${LUA_VER_SH}|' \
		${WRKSRC}/${MAKEFILE}

post-build:
	@${RM} -f ${WRKSRC}/test/lua ${WRKSRC}/test/luac

do-install:
# Programs.
	${MKDIR} ${LUA_BINDIR}
.for f in ${LUA_BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${LUA_BINDIR}
	${LN} -sf ${LUA_SUBDIR}/${f} ${PREFIX}/bin/${f}-${LUA_VER}
.endfor
# Include files.
	${MKDIR} ${LUA_INCDIR}
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${LUA_INCDIR}
# Libraries.
	${MKDIR} ${LUA_LIBDIR}
.for f in ${LUA_LIB}
	${INSTALL_DATA} ${WRKSRC}/lib/lib${f}.a ${LUA_LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/lib${f}.so \
		${LUA_LIBDIR}/lib${f}-${LUA_VER}.so.${LUA_VER_SH}
	@${LN} -sf lib${f}-${LUA_VER}.so.${LUA_VER_SH} ${LUA_LIBDIR}/lib${f}.so
	@${LN} -sf ${LUA_SUBDIR}/lib${f}-${LUA_VER}.so.${LUA_VER_SH} \
		${PREFIX}/lib
	@${LN} -sf lib${f}-${LUA_VER}.so.${LUA_VER_SH} \
		${PREFIX}/lib/lib${f}-${LUA_VER}.so
.endfor
# Manual pages.
.for f in ${LUA_MAN}
	${INSTALL_MAN} ${WRKSRC}/doc/${f} \
		${PREFIX}/man/man1/${f:C/.1$//}-${LUA_VER}.1
.endfor
# Documentation.
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html *.gif ${DOCSDIR}
	${CP} -r ${WRKSRC}/etc ${WRKSRC}/test ${DOCSDIR}
.endif
# Module directories.
	${MKDIR} ${LUA_MODLIBDIR}
	${MKDIR} ${LUA_MODSHAREDIR}

.include <bsd.port.post.mk>
