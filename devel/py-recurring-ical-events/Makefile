PORTNAME=	recurring-ical-events
PORTVERSION=	3.8.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	recurring_ical_events-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Calculate recurrence times of events, todos, alarms and journals based on icalendar RFC5545
WWW=		https://recurring-ical-events.readthedocs.io/en/latest/ \
		https://github.com/niccokunzmann/python-recurring-ical-events

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.27.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}icalendar>=6.1.0<7.0.0:devel/py-icalendar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.1<3.0.0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzdata>=0:devel/py-tzdata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}x-wr-timezone>=1.0.0<3.0.0:devel/py-x-wr-timezone@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
