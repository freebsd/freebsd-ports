PORTNAME=	backports.zoneinfo
DISTVERSION=	0.2.1
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Backport of the standard library module zoneinfo
WWW=		https://zoneinfo.readthedocs.io/en/latest/ \
		https://github.com/pganssle/zoneinfo

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=40.8.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}backports>=0:devel/py-backports@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

# We already have Python 3.7 as minimal supported release, force positive checks
CFLAGS+=	-DATLEAST_37

OPTIONS_DEFINE=	TZDATA
OPTIONS_DEFAULT=TZDATA
TZDATA_DESC=	IANA time zone data support

TZDATA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tzdata>=0:devel/py-tzdata@${PY_FLAVOR}


POST_PLIST=     trim-backports-namespace

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +
	@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/backports/__init__.py*
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/backports/__pycache_

trim-backports-namespace:
	@${REINPLACE_CMD} '/backports\/__init__.py*/d' ${TMPPLIST}
	@${REINPLACE_CMD} '/backports\/__pycache__*/d' ${TMPPLIST}

.include <bsd.port.mk>
