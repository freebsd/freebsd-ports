PORTNAME=	carbon
PORTVERSION=	1.1.10
PORTREVISION=	3
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Backend storage application for graphite
WWW=		https://github.com/graphite-project/carbon

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cachetools>=1.1.0:devel/py-cachetools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service-identity>=0:security/py-service-identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=13.2.0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}txamqp>=0.3:net/py-txamqp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=0:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}whisper>=0.9.10:databases/py-whisper@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	graphite-project
USE_PYTHON=	distutils py3kplist
USE_RC_SUBR=	carbon

MAKE_ENV=	GRAPHITE_NO_PREFIX=yes

NO_ARCH=	yes
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} > 30900
BROKEN=		Python-3.9 is not supported
.endif

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/setup.py

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/examples/init.d
	${RMDIR} ${STAGEDIR}${PREFIX}/examples

.include <bsd.port.post.mk>
