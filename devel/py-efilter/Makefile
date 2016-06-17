# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	efilter
PORTVERSION=	1.2
DISTVERSIONPREFIX=	${PORTEPOCH}!
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	EFILTER query language

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.4.0:devel/py-six
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=2:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}six>=1.4.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}pytz>=2011:devel/py-pytz

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist
WRKSRC=		${WRKDIR}/${DISTNAME:C,!,-,}

post-extract:
	@${CHMOD} -R a+rX ${WRKSRC}
	@${RM} -r ${WRKSRC}/sample_projects

.include <bsd.port.mk>
