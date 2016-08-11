# $FreeBSD$

PORTNAME=	yasm
PORTVERSION=	1.3.0
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
NLS_USES=	gettext iconv
NLS_CONFIGURE_OFF=--disable-nls --without-libiconv-prefix --without-libintl-prefix

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
CFLAGS:=	${CFLAGS:C/-O[0-9]//g}
.endif

INSTALL_TARGET=	install install-man

.include <bsd.port.post.mk>
