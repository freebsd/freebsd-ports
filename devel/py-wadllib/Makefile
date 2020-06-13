# $FreeBSD$

PORTNAME=	wadllib
PORTVERSION=	1.3.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Navigate HTTP resources using WADL files as guides

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	\
	${PYTHON_PKGNAMEPREFIX}lazr.uri>=0:devel/py-lazr.uri@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
