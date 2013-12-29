# Created by: ijliao
# $FreeBSD$

PORTNAME=	yasm
PORTVERSION=	1.2.0
CATEGORIES=	devel lang
MASTER_SITES=	http://www.tortall.net/projects/yasm/releases/

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	A complete rewrite of the NASM assembler

LICENSE=	BSD

OPTIONS_DEFINE=	NLS

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-python --disable-python-bindings
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${ARCH} == "ia64"
CFLAGS:=	${CFLAGS:C/-O[0-9]//g}
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext iconv
.else
CONFIGURE_ARGS+=--disable-nls --without-libiconv-prefix --without-libintl-prefix
.endif

INSTALL_TARGET=	install install-man
MAN1=		yasm.1
MAN7=		yasm_arch.7 yasm_dbgfmts.7 yasm_objfmts.7 yasm_parsers.7

.include <bsd.port.mk>
