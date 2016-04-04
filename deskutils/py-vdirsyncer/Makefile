# $FreeBSD$

PORTNAME=	vdirsyncer
PORTVERSION=	0.9.3
CATEGORIES=	deskutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	che@bein.link
COMMENT=	Synchronize calendars and contacts

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.10.1:devel/py-setuptools_scm
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}atomicwrites>=0.1.4:devel/py-atomicwrites \
		${PYTHON_PKGNAMEPREFIX}click>=3.2:devel/py-click \
		${PYTHON_PKGNAMEPREFIX}icalendar>=3.6:devel/py-icalendar \
		${PYTHON_PKGNAMEPREFIX}lxml>=3.0:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}requests>=2.4.3:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=0.1.3:www/py-requests-toolbelt

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
