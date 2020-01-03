# $FreeBSD$

PORTNAME=	pypuppetdb
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Library to work with PuppetDB's REST API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	pypuppetdb03-*

GH_ACCOUNT=	voxpupuli

post-patch:
	${REINPLACE_CMD} -e '/requirements_for_tests/d' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
