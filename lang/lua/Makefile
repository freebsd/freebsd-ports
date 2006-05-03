# New ports collection makefile for: 	lua
# Date created:				27 June 1999
# Whom:					Richard Kiss <him@richardkiss.com>
#
# $FreeBSD$
#

PORTNAME=	lua
PORTVERSION=	5.1
CATEGORIES=	lang
MASTER_SITES=	http://www.lua.org/ftp/ \
		ftp://ftp.tecgraf.puc-rio.br/pub/lua/ \
		ftp://csg.uwaterloo.ca/pub/lhf/lua/ \
		ftp://ftp.ntua.gr/pub/lang/lua/ \
		ftp://ftp.uni-trier.de/pub/languages/lua/ \
		ftp://ftp.gwdg.de/pub/languages/lua/

MAINTAINER=	him@richardkiss.com
COMMENT=	Small, compilable scripting language providing easy access to C code

MAN1=		lua.1 luac.1

MAKE_ARGS=	bsd

CONFLICTS=	lua-4* lua-5.0*

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html *.css *.gif ${DOCSDIR}
.endif

.if ${MACHINE_ARCH:L} == "amd64"
CFLAGS+=	-fPIC
.endif

.include <bsd.port.mk>
