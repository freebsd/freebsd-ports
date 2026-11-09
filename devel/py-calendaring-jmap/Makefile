PORTNAME=	calendaring-jmap
PORTVERSION=	2.0.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	calendaring_jmap-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JMAP (RFC 8620) calendar client library
WWW=		https://calendaring-jmap.readthedocs.io/en/stable/ \
		https://github.com/PyCalendar/calendaring-jmap

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0.5.0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.32.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}icalendar>=7.3.0:devel/py-icalendar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}niquests>=3.21.1:www/py-niquests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0.3:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wassima>=2.1.5:security/py-wassima@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
