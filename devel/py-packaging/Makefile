# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	packaging
PORTVERSION=	17.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core utilities for Python packages

LICENSE=	APACHE20 BSD2CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.APACHE
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSE.BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>=2.0.2:devel/py-pyparsing@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

.include <bsd.port.mk>
