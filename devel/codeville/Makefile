PORTNAME=		codeville
PORTVERSION=	0.1.18
CATEGORIES=		devel python
MASTER_SITES=	https://BSDforge.com/projects/source/devel/codeville/

MAINTAINER=		portmaster@bsdforge.com
COMMENT=		Anarchic control version system without unnecessary re-merges
WWW=		https://bsdforge.com/projects/devel/codeville/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN=		Unfetchable

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR}

USES=		python tar:txz
USE_PYTHON=	distutils autoplist noflavors
NO_ARCH=	yes

PORTEXAMPLES=	cdvserver.conf.sample

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
