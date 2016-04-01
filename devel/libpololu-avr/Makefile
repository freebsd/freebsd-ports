# $FreeBSD$

PORTNAME=	libpololu-avr
PORTVERSION=	140513
CATEGORIES=	devel
MASTER_SITES=	http://www.pololu.com/file/download/
EXTRACT_SUFX=	.zip?file_id=0J757

MAINTAINER=	jonathan@FreeBSD.org
COMMENT=	Support libraries for Pololu robots

LICENSE=	MIT

BUILD_DEPENDS=	avr-gcc:devel/avr-gcc \
		${LOCALBASE}/avr/lib/libc.a:devel/avr-libc

USES=		gmake zip

PREFIX=		${LOCALBASE}/avr

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ENV=	LIB=${STAGEDIR}${PREFIX}/lib
ALL_TARGET=	library_files

.include <bsd.port.mk>
