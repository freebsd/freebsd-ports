# $FreeBSD$

PORTNAME=	cluster
PORTVERSION=	1.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Create several groups (clusters) of objects from a list in Python

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	exhuma
GH_PROJECT=	python-cluster

USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

PORTSCOUT=	skipv:regression

.include <bsd.port.mk>
