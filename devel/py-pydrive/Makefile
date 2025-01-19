PORTNAME=	pydrive
PORTVERSION=	1.3.1
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyDrive-${PORTVERSION}

MAINTAINER=	paul@gromit.dlib.vt.edu
COMMENT=	Google drive api made easy
WWW=		https://github.com/googledrive/PyDrive

LICENSE=	APACHE20

DEPRECATED=	Upstream repo archived on Jul 22, 2021
EXPIRATION_DATE=2025-01-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-python-client>=1.5.2:www/py-google-api-python-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauth2client>=4.0.0:security/py-oauth2client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.11:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
