PORTNAME=	gitlab-webhook-handler
DISTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	devel www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gwh-${DISTVERSION}

MAINTAINER=	michael.osipov@siemens.com
COMMENT=	Webhook Handler for GitLab
WWW=		https://github.com/ahebrank/gitlab-webhook-handler

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=1.0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.19.0:www/py-requests@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	python
USE_PYTHON=	autoplist concurrent distutils
PYDISTUTILS_PKGNAME=	gwh

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|python -m gwh|${PYTHON_VERSION} -m gwh|' \
		${WRKSRC}/gwh/__main__.py

.include <bsd.port.mk>
