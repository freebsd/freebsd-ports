PORTNAME=	recurring-ical-events
PORTVERSION=	2.2.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	recurring_ical_events-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python module which repeats ICalendar events by RRULE, RDATE and EXDATE
WWW=		https://github.com/niccokunzmann/python-recurring-ical-events

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}icalendar>=4.0.0<7.0.0:devel/py-icalendar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.1<3.0.0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzdata>=0:devel/py-tzdata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}x-wr-timezone>=0.0<1:devel/py-x-wr-timezone@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
