PORTNAME=	rich-toolkit
DISTVERSION=	0.14.8
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	rich_toolkit-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Rich toolkit for building command-line applications
WWW=		https://pypi.python.org/project/rich-toolkit/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR} \

USES=		python
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
