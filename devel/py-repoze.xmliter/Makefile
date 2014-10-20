# $FreeBSD$

PORTNAME=	repoze.xmliter
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Wrapper for lxml trees which serializes to string upon iteration

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=2.1.1:${PORTSDIR}/devel/py-lxml

USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
