# $FreeBSD$

PORTNAME=	rekall-efilter
PORTVERSION=	1.6.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	EFILTER query language with Rekall specific modifications

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}efilter-[0-9]*

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>2:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.16.0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.4.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2011:devel/py-pytz@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python zip
USE_PYTHON=	distutils autoplist

post-extract:
	@${RM} -r ${WRKSRC}/sample_projects

.include <bsd.port.mk>
