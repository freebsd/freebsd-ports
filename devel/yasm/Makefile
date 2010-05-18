# ex:ts=8
# Ports collection makefile for:	yasm
# Date created:			Apr 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yasm
PORTVERSION=	1.0.1
CATEGORIES=	devel lang
MASTER_SITES=	http://www.tortall.net/projects/yasm/releases/

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	A complete rewrite of the NASM assembler

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-python --disable-python-bindings
CONFIGURE_ENV+=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
CFLAGS:=	${CFLAGS:C/-O[0-9]//g}
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls --without-libiconv-prefix --without-libintl-prefix
.else
USE_GETTEXT=	yes
USE_ICONV=	yes
.endif

INSTALL_TARGET=	install install-man
MAN1=		yasm.1
MAN7=		yasm_arch.7 yasm_dbgfmts.7 yasm_objfmts.7 yasm_parsers.7

.include <bsd.port.post.mk>
