PORTNAME=	libxmp
DISTVERSION=	4.7.4
CATEGORIES=	audio
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${PORTNAME}-${DISTVERSION}/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Module rendering library for xmp
WWW=		https://xmp.sourceforge.net/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/docs/COPYING

USES=		cmake:testing pathfix
USE_LDCONFIG=	yes

PLIST_SUB=	DISTVERSION=${DISTVERSION}

CMAKE_TESTING_ON=	WITH_UNIT_TESTS

CMAKE_OFF=	BUILD_STATIC \
		LIBXMP_DOCS

.include <bsd.port.mk>
