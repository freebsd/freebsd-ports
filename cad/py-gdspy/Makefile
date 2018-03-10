# $FreeBSD$

PORTNAME=	gdspy
PORTVERSION=	1.1.2
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	cad python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Python module for creating GDSII stream files

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	heitzmann

OPTIONS_DEFINE=	EXAMPLES
EXAMPLES_PLIST_FILES=	${EXAMPLESDIR}/tutorial.py

post-install:
	cd ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME} && \
	    ${STRIP_CMD} boolext.so clipper.so

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/tutorial.py \
	    ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
