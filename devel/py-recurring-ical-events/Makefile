PORTNAME=	recurring-ical-events
PORTVERSION=	2.1.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	recurring_ical_events-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python module which repeats ICalendar events by RRULE, RDATE and EXDATE
WWW=		https://github.com/niccokunzmann/python-recurring-ical-events

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}icalendar>=0<6.0.0:devel/py-icalendar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.8.1:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2023.3,1:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}x-wr-timezone>=0.0.5<1.0.0:devel/py-x-wr-timezone@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
