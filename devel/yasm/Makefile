# Created by: ijliao
# $FreeBSD$

PORTNAME=	yasm
PORTVERSION=	1.2.0
CATEGORIES=	devel lang
MASTER_SITES=	http://www.tortall.net/projects/yasm/releases/

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	Complete rewrite of the NASM assembler

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	NLS

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-python --disable-python-bindings
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

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

.include <bsd.port.mk>
