# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	logan
PORTVERSION=	0.7.1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xmj@chaot.net
COMMENT=	Logan is a toolkit for running standalone Django applications

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>0:${PORTSDIR}/www/py-django
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>0:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}nose>=1.1.2:${PORTSDIR}/devel/py-nose

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.rst
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	dcramer
GH_TAGNAME=	82a0ca7

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}/README.rst

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
