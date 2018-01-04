# $FreeBSD$

PORTNAME=	easyprocess
PORTVERSION=	0.2.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	EasyProcess-${PORTVERSION}

MAINTAINER=	daniel@blodan.se
COMMENT=	Easy to use python subprocess interface

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paver>0:devel/py-paver@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cog>=2.3:devel/py-cog@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${FLAVOR}

NO_ARCH=	YES
USE_PYTHON=	autoplist distutils
USES=		python

.include <bsd.port.mk>
