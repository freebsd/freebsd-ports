PORTNAME=	biopython
DISTVERSION=	1.85
PORTREVISION=	2
CATEGORIES=	biology python
MASTER_SITES=	http://www.biopython.org/DIST/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mauricio@arareko.net
COMMENT=	Collection of Python modules for bioinformatics
WWW=		https://biopython.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=		REPORTLAB
OPTIONS_DEFAULT=	REPORTLAB

REPORTLAB_DESC=		PDF support in Bio.Graphics module
REPORTLAB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}reportlab>0:print/py-reportlab@${PY_FLAVOR}

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Bio/*.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Bio/*/*.so

.include <bsd.port.mk>
