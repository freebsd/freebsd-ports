PORTNAME=	soundcloud
PORTVERSION=	0.5.0
CATEGORIES=	audio devel www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Friendly wrapper library for the Soundcloud API

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0.14.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0:devel/py-simplejson@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=1.1.2:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fudge>=1.0.3:devel/py-fudge@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

PORTDOCS=	README.rst
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${WRKSRC} && nosetests-${PYTHON_VER} --with-doctest

.include <bsd.port.mk>
