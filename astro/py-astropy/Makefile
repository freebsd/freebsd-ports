# Created by: nwhitehorn
# $FreeBSD$

PORTNAME=	astropy
PORTVERSION=	3.1.1
CATEGORIES=	astro
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nwhitehorn@FreeBSD.org
COMMENT=	Community-developed python astronomy tools

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

POST_PLIST=	rm-bogus-plist-files

rm-bogus-plist-files: # https://github.com/astropy/astropy/issues/8364
	@${REINPLACE_CMD} '/.*\.\.\/wcs\/tests/d' ${TMPPLIST}

.include <bsd.port.mk>
