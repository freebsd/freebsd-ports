PORTNAME=	valerius
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	biology python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bioinformatics tools
WWW=		https://github.com/samirelanduk/valerius

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	samirelanduk

NO_ARCH=	yes

.include <bsd.port.mk>
