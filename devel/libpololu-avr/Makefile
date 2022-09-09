PORTNAME=	libpololu-avr
PORTVERSION=	151002
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	jonathan@FreeBSD.org
COMMENT=	Support libraries for Pololu robots
WWW=		https://www.pololu.com/docs/0J20

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/avr/lib/libc.a:devel/avr-libc
RUN_DEPENDS=	${LOCALBASE}/avr/lib/libc.a:devel/avr-libc

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	pololu

MAKE_ENV=	LIB=${STAGEDIR}${PREFIX}/avr/lib
ALL_TARGET=	library_files

.include <bsd.port.mk>
