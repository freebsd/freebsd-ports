# $FreeBSD$

PORTNAME=	vdirsyncer
PORTVERSION=	0.16.3
CATEGORIES=	deskutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	che@bein.link
COMMENT=	Synchronize calendars and contacts

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.10.1:devel/py-setuptools_scm@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}atomicwrites>=0.1.7:devel/py-atomicwrites@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=5.0:devel/py-click@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-log>=0.1.3:devel/py-click-log@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-threading>=0.1.2:devel/py-click-threading@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.4.1:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=0.4.0:www/py-requests-toolbelt@${FLAVOR}

USES=		python:3.4+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

OPTIONS_DEFINE=	GOOGLE

GOOGLE_DESC=	Enable Google Calendar support
GOOGLE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=0:www/py-requests-oauthlib@${FLAVOR}

.include <bsd.port.mk>
