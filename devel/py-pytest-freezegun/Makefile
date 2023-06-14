PORTNAME=	pytest-freezegun
PORTVERSION=	0.4.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Wrap tests with fixtures in freeze_time
WWW=		https://github.com/ktosiek/pytest-freezegun

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# unless the upstream fixes the problem, this port should be probably deprecated, see https://github.com/ktosiek/pytest-freezegun/issues/43
BROKEN=		causes INTERNALERROR failures in PyTest in many python-based ports, based on the assessment in this comment: https://github.com/pytest-dev/pytest/issues/10846#issuecomment-1487971534

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}freezegun>0.3:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=3.0.0:devel/py-pytest@${PY_FLAVOR}

USES=		python zip
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
