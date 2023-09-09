PORTNAME=	hsluv
DISTVERSION=	5.0.3
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Human-friendly HSL
WWW=		https://www.hsluv.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_PYTHON=	distutils autoplist pytest # 1 test fails, see https://github.com/hsluv/hsluv/issues/87

NO_ARCH=	yes

.include <bsd.port.mk>
