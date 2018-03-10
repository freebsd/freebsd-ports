# Created by: R.F. Smith <rsmith@xs4all.nl>
# $FreeBSD$

PORTNAME=		stltools
PORTVERSION=		3.2
PORTREVISION=		2
CATEGORIES=		graphics python
MASTER_SITES=		http://rsmith.home.xs4all.nl/files/
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=		rsmith@xs4all.nl
COMMENT=		Converts STL models to POV-Ray meshes or PostScript/PDF images

LICENSE=		BSD2CLAUSE

RUN_DEPENDS=		${PYNUMPY}

USES=			zip python:2.7
USE_PYTHON=		distutils
NO_ARCH=		yes

DOCS=			README.txt
EXAMPLES=		test/cube.stl test/cube_bin.stl

OPTIONS_DEFINE=		PYCAIRO DOCS EXAMPLES
PYCAIRO_DESC=		Use (py)Cairo to enable stl2pdf to function.
PYCAIRO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>1.8:graphics/py-cairo@${FLAVOR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
