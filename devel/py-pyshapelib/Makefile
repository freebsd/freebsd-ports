# Created by: TAOKA Fumiyoshi <fmysh@iijmio-mail.jp>
# $FreeBSD$

PORTNAME=	pyshapelib
PORTVERSION=	1.0
CATEGORIES=	devel python geography
MASTER_SITES=	http://wald.intevation.org/frs/download.php/899/:py \
		http://download.osgeo.org/shapelib/:c
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:py ${SHAPELIB}${EXTRACT_SUFX}:c

MAINTAINER=	fmysh@iijmio-mail.jp
COMMENT=	Python bindings for Shapelib

LICENSE=	LGPL20

USES=		python:2.7
USE_LDCONFIG=	yes
USE_PYTHON=	distutils

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

PORTDOCS=	NEWS README
PORTEXAMPLES=	pytest.py

# pyshapelib requires shapelib source to build
SHAPELIB=	shapelib-1.3.0

post-extract:
	${LN} -s ${WRKDIR}/${SHAPELIB} ${WRKDIR}/shapelib

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
