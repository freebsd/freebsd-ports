# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	efilter
PORTVERSION=	1.5
DISTVERSIONPREFIX=	${PORTEPOCH}-
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	EFILTER query language

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.4.0:devel/py-six@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=2:devel/py-dateutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.4.0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2011:devel/py-pytz@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

post-extract:
	@${RM} -r ${WRKSRC}/sample_projects

.include <bsd.port.mk>
