# $FreeBSD$

PORTNAME=	repoze.xmliter
PORTVERSION=	0.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Wrapper for lxml trees which serializes to string upon iteration

LICENSE=	REPOZE
LICENSE_NAME=	Repoze License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=2.1.1:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future

USES=		python zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
