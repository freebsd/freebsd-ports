PORTNAME=		codeville
PORTVERSION=	0.1.18
CATEGORIES=		devel python
MASTER_SITES=	https://BSDforge.com/projects/source/devel/codeville/

MAINTAINER=		portmaster@bsdforge.com
COMMENT=		Anarchic control version system without unnecessary re-merges

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR}

USES=		python:3.7+ tar:txz
USE_PYTHON=	distutils autoplist noflavors
NO_ARCH=	yes

PORTEXAMPLES=	cdvserver.conf.sample

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
