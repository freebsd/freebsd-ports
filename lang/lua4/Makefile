# Created by: Richard Kiss <him@richardkiss.com>
# $FreeBSD$

PORTNAME=	lua
PORTVERSION=	4.0.1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.tecgraf.puc-rio.br/pub/lua/ \
		ftp://csg.uwaterloo.ca/pub/lhf/lua/ \
		ftp://ftp.ntua.gr/pub/lang/lua/ \
		ftp://ftp.uni-trier.de/pub/languages/lua/ \
		ftp://ftp.gwdg.de/pub/languages/lua/

MAINTAINER=	him@richardkiss.com
COMMENT=	Small, compilable scripting language providing easy access to C code

DEPRECATED=	Lua4 is EOLed
EXPIRATION_DATE=	2013-11-18

USE_LDCONFIG=	yes
USE_LUA=	4.0
LUA_COMPS=	# only define variables
ALL_TARGET=	all so

MAN1=		lua-${LUA_VER}.1 luac-${LUA_VER}.1
DOCSDIR=	${PREFIX}/share/doc/${LUA_SUBDIR}
LATEST_LINK=	${LUA_SUBDIR}

LUA_BIN=	lua luac
LUA_LIB=	lua lualib
LUA_MAN=	${LUA_BIN:S/$/.1/}

MAKE_JOBS_UNSAFE=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|^#(POPEN=.*)|\1|; \
		 s|^(CC=).*|\1 ${CC}|; \
		 s|^(CFLAGS=) -O2 (.*)|\1 ${CFLAGS} \2|; \
		 s|^(V=)[[:digit:]]\.0|\1 ${LUA_VER}|' \
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
	${INSTALL_PROGRAM} ${WRKSRC}/lib/lib${f}.a ${LUA_LIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/lib/lib${f}.so \
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
	${MKDIR} ${LUA_MODSHAREDIR}
	${MKDIR} ${LUA_MODLIBDIR}

.include <bsd.port.post.mk>
