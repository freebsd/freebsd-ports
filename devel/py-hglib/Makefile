PORTNAME=	hglib
PORTVERSION=	2.6.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Library with a fast, convenient interface to Mercurial

LICENSE=	MIT

RUN_DEPENDS+=	${PY_MERCURIAL}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
