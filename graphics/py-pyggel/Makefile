# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyggel
PORTVERSION=	0.08
DISTVERSIONSUFFIX=	-alpha4c
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME:tu}-V${DISTVERSION}${DISTVERSIONSUFFIX}
DIST_SUBDIR=	python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koalative@gmail.com
COMMENT=	Python Graphical Game Engine and Libraries

LICENSE=	LGPL3 Public_Domain
LICENSE_COMB=	dual
LICENSE_NAME_Public_Domain=	Public Domain
LICENSE_TEXT_Public_Domain=	Public Domain
LICENSE_PERMS_Public_Domain=dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${PYNUMPY} \
		${PYGAME} \
		${PYTHON_PKGNAMEPREFIX}opengl>=0:${PORTSDIR}/graphics/py-opengl \
		${PYTHON_PKGNAMEPREFIX}imaging>=0:${PORTSDIR}/graphics/py-imaging

USES=		dos2unix zip
DOS2UNIX_GLOB=	*.mtl *.py *.txt
USE_PYTHON=	2
NO_BUILD=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

PORTDOCS=	Readme.txt
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|data_files =|#data_files =|' \
		${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.if ${PORT_OPTIONS:MEXAMPLES}
	@(cd ${WRKSRC}/examples_and_tutorials && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR}/examples_and_tutorials)
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${EXAMPLESDIR})
. for f in test_FBO test_camera test_gui test_mesh test_particle test_texture_swap
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${f}.py ${STAGEDIR}${EXAMPLESDIR})
. endfor
.endif

.include <bsd.port.mk>
