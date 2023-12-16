PORTNAME=	x-wr-timezone
PORTVERSION=	0.0.6
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	x_wr_timezone-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python module and program to convert calendars using X-WR-TIMEZONE to standard ones
WWW=		https://github.com/niccokunzmann/x-wr-timezone

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}icalendar>=0:devel/py-icalendar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0,1:devel/py-pytz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
