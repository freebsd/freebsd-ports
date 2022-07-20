PORTNAME=	fabric3
DISTVERSION=	1.14
DISTVERSIONSUFFIX=	.post1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Fabric3-${DISTVERSIONFULL}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Python tool for remote execution and deployment

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	py*-fabric # bin/fab

NO_ARCH=	yes

.include <bsd.port.mk>
