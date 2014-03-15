# Created by: Mark Linimon <linimon@lonesome.com>
# $FreeBSD$

PORTNAME=	dns
PORTVERSION=	3.0.4
CATEGORIES=	dns python
MASTER_SITES=	https://launchpad.net/${DISTNAME}/trunk/${PORTVERSION}/+download/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	3
DISTNAME=	py3dns-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	DNS (Domain Name Service) library for Python 3

LICENSE=	CNRI
LICENSE_NAME=	CNRI LICENSE AGREEMENT
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

PYDISTUTILS_AUTOPLIST=	yes
USE_PYDISTUTILS=yes
USE_PYTHON=	3

.include <bsd.port.mk>
