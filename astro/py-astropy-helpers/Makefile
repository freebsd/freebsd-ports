PORTNAME=	astropy-helpers
DISTVERSION=	4.0.1
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Utilities for building and installing packages in Astropy ecosystem
WWW=		https://github.com/astropy/astropy-helpers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
