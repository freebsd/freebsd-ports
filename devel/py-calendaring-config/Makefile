PORTNAME=	calendaring-config
PORTVERSION=	0.5.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	calendaring_config-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Shared configuration file of caldav, calendaring and calendaring-jmap
WWW=		https://github.com/PyCalendar/calendaring-config

LICENSE=	APACHE20 GPLv3+
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/COPYING.APACHE
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING.GPL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.27:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
