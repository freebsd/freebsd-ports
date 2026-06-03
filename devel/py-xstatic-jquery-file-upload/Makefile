PORTNAME=	xstatic-jquery-file-upload
PORTVERSION=	10.32.0.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	xstatic_jquery_file_upload-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	jQuery-File-Upload ${PORTVERSION:R} (XStatic packaging standard)
WWW=		https://github.com/xstatic-py/xstatic-jquery-file-upload

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
