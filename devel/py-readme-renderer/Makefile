PORTNAME=	readme-renderer
PORTVERSION=	46.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	readme_renderer-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for rendering "readme" descriptions
WWW=		https://github.com/pypa/readme_renderer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>=0.21.2,1:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nh3>=0.2.14:www/py-nh3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.5.1:textproc/py-pygments@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	MD
OPTIONS_DEFAULT=MD
MD_DESC=	Markdown support

MD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}comrak>=0.0.13:textproc/py-comrak@${PY_FLAVOR}

.include <bsd.port.mk>
