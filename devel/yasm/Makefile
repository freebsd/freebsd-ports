PORTNAME=	yasm
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	devel lang
MASTER_SITES=	https://www.tortall.net/projects/yasm/releases/

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	Complete rewrite of the NASM assembler
WWW=		https://yasm.tortall.net/

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	NLS

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS+=--disable-python --disable-python-bindings
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
NLS_USES=	gettext iconv
NLS_CONFIGURE_OFF=--disable-nls --without-libiconv-prefix --without-libintl-prefix

INSTALL_TARGET=	install install-man

.include <bsd.port.mk>
