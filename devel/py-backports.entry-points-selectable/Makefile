PORTNAME=	backports.entry-points-selectable
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	backports.entry_points_selectable-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Compatibility shim providing selectable entry points for older implementations
WWW=		https://github.com/jaraco/backports.entry_points_selectable

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=56:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4.1:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}backports>=0:devel/py-backports@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes


POST_PLIST=     trim-backports-namespace

post-install:
	@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/backports/__init__.py*
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/backports/__pycache_

trim-backports-namespace:
	@${REINPLACE_CMD} '/backports\/__init__.py*/d' ${TMPPLIST}
	@${REINPLACE_CMD} '/backports\/__pycache__*/d' ${TMPPLIST}

.include <bsd.port.mk>
