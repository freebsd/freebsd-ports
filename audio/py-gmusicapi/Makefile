# Created by: Thomas Zander <riggs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gmusicapi
PORTVERSION=	10.1.2
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Unofficial Python API for Google Play Music

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=1.3.0:devel/py-appdirs@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.2:devel/py-dateutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=3.4.0:devel/py-decorator@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.0:devel/py-future@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=1.0.1:devel/py-mock@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mutagen>=1.18:audio/py-mutagen@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauth2client>=1.2:security/py-oauth2client@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gpsoauth>=0.0:security/py-gpsoauth@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=2.5.0:devel/py-protobuf@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.3.0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}validictory>=0.9.3:devel/py-validictory@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ndg_httpsclient>0:net/py-ndg_httpsclient@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}MechanicalSoup>0:www/py-MechanicalSoup@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>0:devel/py-pyasn1@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	simon-weber

NO_ARCH=	yes

.include <bsd.port.mk>
