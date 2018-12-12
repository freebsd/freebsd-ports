# $FreeBSD$

PORTNAME=	belcard
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	https://www.linphone.org/releases/sources/belcard/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	vCard support library

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libbelr.so:textproc/belr

USES=		cmake:outsource compiler:c++11-lib
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_STATIC=NO -DENABLE_STRICT=NO -DENABLE_UNIT_TESTS=NO
WRKSRC= 	${WRKDIR}/${DISTNAME}-0

.include <bsd.port.mk>
