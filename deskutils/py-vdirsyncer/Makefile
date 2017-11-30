# $FreeBSD$

PORTNAME=	vdirsyncer
PORTVERSION=	0.12.1
CATEGORIES=	deskutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	che@bein.link
COMMENT=	Synchronize calendars and contacts

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.10.1:devel/py-setuptools_scm@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}atomicwrites>=0.1.7:devel/py-atomicwrites@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=5.0:devel/py-click@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-log>=0.1.3:devel/py-click-log@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-threading>=0.1.2:devel/py-click-threading@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}icalendar>=3.6:devel/py-icalendar@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=3.1:devel/py-lxml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.4.1:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=0.4.0:www/py-requests-toolbelt@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
