PORTNAME=	annotated-doc
PORTVERSION=	0.0.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	annotated_doc-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Document parameters, class attributes, etc, with Annotated
WWW=		https://github.com/fastapi/annotated-doc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>=0:devel/py-pdm-backend@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
