# $FreeBSD$

PORTNAME=	duktape
PORTVERSION=	1.0.2
CATEGORIES=	lang devel
MASTER_SITES=	http://duktape.org/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Embeddable Javascript engine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=	readline tar:xz

MAKEFILE=	Makefile.cmdline
ALL_TARGET=	#

PLIST_FILES=	bin/duk

# for readline
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-I${LOCALBASE}/lib

MAKE_ARGS=	CC="${CC}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/duk ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
