# Created by: Thomas Zander <riggs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gmusicapi
PORTVERSION=	11.0.1
PORTREVISION=	1
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Unofficial Python API for Google Play Music

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Google Play Music is going away: https://github.com/simon-weber/gmusicapi/issues/673
EXPIRATION_DATE=2020-12-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=1.3.0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.2:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=3.4.0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=1.0.1:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mutagen>=1.18:audio/py-mutagen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauth2client>=1.2:security/py-oauth2client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gpsoauth>=0.0:security/py-gpsoauth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=2.5.0:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.3.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}validictory>=0.9.3:devel/py-validictory@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ndg_httpsclient>0:net/py-ndg_httpsclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mechanicalsoup>0:www/py-mechanicalsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>0:devel/py-pyasn1@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	simon-weber

NO_ARCH=	yes

.include <bsd.port.mk>
