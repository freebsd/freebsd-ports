# Created by: Thomas Zander <riggs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gmusicapi
PORTVERSION=	7.0.0
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Unofficial Python API for Google Play Music

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=1.3.0:${PORTSDIR}/devel/py-appdirs \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.2:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}decorator>=3.4.0:${PORTSDIR}/devel/py-decorator \
		${PYTHON_PKGNAMEPREFIX}mock>=1.0.1:${PORTSDIR}/devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}mutagen>=1.18:${PORTSDIR}/audio/py-mutagen \
		${PYTHON_PKGNAMEPREFIX}oauth2client>=1.2:${PORTSDIR}/security/py-oauth2client \
		${PYTHON_PKGNAMEPREFIX}gpsoauth>=0.0:${PORTSDIR}/security/py-gpsoauth \
		${PYTHON_PKGNAMEPREFIX}protobuf>=2.5.0:${PORTSDIR}/devel/py-protobuf \
		${PYTHON_PKGNAMEPREFIX}requests>=2.3.0:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}validictory>=0.9.3:${PORTSDIR}/devel/py-validictory \
		${PYTHON_PKGNAMEPREFIX}ndg_httpsclient>0:${PORTSDIR}/net/py-ndg_httpsclient \
		${PYTHON_PKGNAMEPREFIX}MechanicalSoup>0:${PORTSDIR}/www/py-MechanicalSoup \
		${PYTHON_PKGNAMEPREFIX}openssl>0:${PORTSDIR}/security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}pyasn1>0:${PORTSDIR}/devel/py-pyasn1

USE_GITHUB=	yes
GH_ACCOUNT=	simon-weber
GH_PROJECT=	gmusicapi
GH_TAGNAME=	18ff98e

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
