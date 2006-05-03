# New ports collection makefile for: 	lua
# Date created:				27 June 1999
# Whom:					Richard Kiss <him@richardkiss.com>
#
# $FreeBSD$
#

PORTNAME=	lua
PORTVERSION=	5.0.2
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.lua.org/ftp/ \
		ftp://ftp.tecgraf.puc-rio.br/pub/lua/ \
		ftp://csg.uwaterloo.ca/pub/lhf/lua/ \
		ftp://ftp.ntua.gr/pub/lang/lua/ \
		ftp://ftp.uni-trier.de/pub/languages/lua/ \
		ftp://ftp.gwdg.de/pub/languages/lua/

MAINTAINER=	him@richardkiss.com
COMMENT=	Small, compilable scripting language providing easy access to C code

LATEST_LINK=	lua50
MAN1=		lua.1 luac.1
ALL_TARGET=	all so
INSTALL_TARGET=	install soinstall
INSTALLS_SHLIB=	YES

do-configure:
	${REINPLACE_CMD} \
		-e 's|^\(MYCFLAGS=\).*$$|\1 ${CFLAGS}|' \
		-e 's|^\(LOADLIB=\).*$$|\1 -DUSE_DLOPEN=1|' \
		-e 's|^\(CC=\).*$$|\1 ${CC}|' \
		-e 's|^\(STRIP=\).*$$|\1 ${STRIP_CMD}|' \
		-e 's|^\(INSTALL_ROOT=\).*$$|\1 ${PREFIX}|' \
		-e 's|^\(INSTALL_EXEC=\).*$$|\1 ${INSTALL_PROGRAM}|' \
		-e 's|^\(INSTALL_DATA=\).*$$|\1 ${INSTALL_DATA}|' \
		-e 's|^#\(USERCONF.*READLINE.*\)$$|\1|' \
		-e 's|^\(EXTRA_LIBS=\).*$$|\1 -lm -lreadline -lhistory -lncurses|' \
		-e 's|V=5.0|V=5|' \
		${WRKSRC}/config

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html *.gif ${DOCSDIR}
.endif

.if ${MACHINE_ARCH:L} == "amd64"
CFLAGS+=	-fPIC
.endif

.include <bsd.port.mk>
