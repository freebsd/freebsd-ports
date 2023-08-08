PORTNAME=	fabric3
DISTVERSION=	1.14
DISTVERSIONSUFFIX=	.post1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Fabric3-${DISTVERSIONFULL}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Python tool for remote execution and deployment
WWW=		https://github.com/mathiasertl/fabric/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	py*-fabric # bin/fab

NO_ARCH=	yes

.include <bsd.port.mk>
