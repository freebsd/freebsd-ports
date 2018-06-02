# $FreeBSD$

PORTNAME=	python-subunit
DISTVERSION=	1.3.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	freebsd_ports@k-worx.org
COMMENT=	Python implementation of subunit test streaming protocol

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}extras>=0:devel/py-extras@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mimeparse>=0:devel/py-mimeparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testtools>=0.9.34:devel/py-testtools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unittest2>=1.0.0:devel/py-unittest2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes
PORTDOCS=	NEWS README.rst

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
