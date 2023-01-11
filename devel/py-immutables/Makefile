PORTNAME=	immutables
PORTVERSION=	0.19
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Immutable collections
WWW=		https://github.com/MagicStack/immutables

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7.4.3:devel/py-typing-extensions@${PY_FLAVOR}
.endif

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.post.mk>
