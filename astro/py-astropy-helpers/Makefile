PORTNAME=	astropy-helpers
DISTVERSION=	4.0.1
CATEGORIES=	astro
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Utilities for building and installing packages in Astropy ecosystem

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
