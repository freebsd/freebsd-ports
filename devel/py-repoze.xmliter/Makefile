# $FreeBSD$

PORTNAME=	repoze.xmliter
PORTVERSION=	0.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Wrapper for lxml trees which serializes to string upon iteration

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=2.1.1:${PORTSDIR}/devel/py-lxml

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
USE_ZIP=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
