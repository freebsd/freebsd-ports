PORTNAME=	shroud
DISTVERSION=	0.12.2-20220929
CATEGORIES=	devel
PKGNAMESUFFIX=	-wrapper-generator

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fortran and Python wrapper generator for C and C++ libraries
WWW=		https://github.com/LLNL/shroud

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist noflavors

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_TAGNAME=	f5a1aec

NO_ARCH=	yes

.include <bsd.port.mk>
