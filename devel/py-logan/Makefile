# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	logan
PORTVERSION=	0.5.10
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xmj@chaot.net
COMMENT=	Logan is a toolkit for running standalone Django applications

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>0:${PORTSDIR}/www/py-django
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>0:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}nose>=1.1.2:${PORTSDIR}/devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}unittest2:${PORTSDIR}/devel/py-unittest2

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
PORTDOCS=	README.rst

DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	dcramer
GH_COMMIT=	7bf71b5
GH_TAGNAME=	0.5.10

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}/README.rst

check test: build
	cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
