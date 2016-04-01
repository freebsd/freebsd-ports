# Created by: R.F. Smith <rsmith@xs4all.nl>
# $FreeBSD$

PORTNAME=		stltools
PORTVERSION=		3.2
PORTREVISION=	1
CATEGORIES=		graphics python
MASTER_SITES=		http://rsmith.home.xs4all.nl/files/
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=		rsmith@xs4all.nl
COMMENT=		Converts STL models to POV-Ray meshes or PostScript/PDF images

LICENSE=		BSD2CLAUSE

RUN_DEPENDS=		${PYNUMPY}

USES=			zip python:2.7
USE_PYTHON=		distutils

DOCS=			README.txt
EXAMPLES=		test/cube.stl test/cube_bin.stl

OPTIONS_DEFINE=		PYCAIRO DOCS
PYCAIRO_DESC=		Use (py)Cairo to enable stl2pdf to function.

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYCAIRO}
RUN_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}cairo>1.8:graphics/py-cairo
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
