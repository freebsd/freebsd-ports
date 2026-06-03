PORTNAME=	icalendar-searcher
PORTVERSION=	1.0.5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	icalendar_searcher-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Search, filter and sort iCalendar components
WWW=		https://github.com/pycalendar/icalendar-searcher

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}icalendar>=6.0:devel/py-icalendar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}recurring-ical-events>=3.8.0:devel/py-recurring-ical-events@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	COLLATION
COLLATION_DESC=	Collation support via PyICU

COLLATION_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyicu>=0:devel/py-pyicu@${PY_FLAVOR}

.include <bsd.port.mk>
