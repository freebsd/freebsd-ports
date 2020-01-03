# $FreeBSD$

PORTNAME=	pypuppetdb
PORTVERSION=	0.3.3
DISTVERSIONPREFIX=	v
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	03

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Library to work with PuppetDB's REST API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Use databases/py-pypuppetdb instead
EXPIRATION_DATE=2020-04-01

CONFLICTS_INSTALL=	pypuppetdb-*
USE_GITHUB=	yes
GH_ACCOUNT=	voxpupuli

USES=	python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
