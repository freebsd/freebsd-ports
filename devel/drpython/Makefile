# Created by: vsevolod
# $FreeBSD$

PORTNAME=	drpython
PORTVERSION=	3.11.4
PORTREVISION=	6
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/DrPython%20%283.x%29/${PORTVERSION}
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}
DISTNAME=	DrPython_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Highly customizable cross-platform ide to aid programming in Python

LICENSE=	GPLv2

# fails to build in presence if installed self
CONFLICTS_BUILD=	${PORTNAME}${PYTHON_PKGNAMESUFFIX}-[0-9]*

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx
RUN_DEPENDS=	xdg-open:devel/xdg-utils

NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		compiler:c++11-lib python zip
USE_PYTHON=	autoplist distutils
USE_WX=		3.0+
WX_COMPS=	python:lib

PLIST_FILES=	bin/drpython

DESKTOP_ENTRIES="DrPython" "Python editor and IDE" \
		"${PYTHONPREFIX_SITELIBDIR}/drpython/bitmaps/drpython.png" \
		"drpython" "Development;IDE;" ""

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${CHOSEN_COMPILER_TYPE} == gcc
MAKE_ENV+=	LD_LIBRARY_PATH="${LOCALBASE}/lib/${CC}:$$LD_LIBRARY_PATH"
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/postinst.py/d' ${WRKSRC}/setup.py
	@${RM} ${WRKSRC}/setup.cfg
	@${REINPLACE_CMD} -e \
		's|firefox|xdg-open|' ${WRKSRC}/drPreferences.py
	@${REINPLACE_CMD} -e 's|%%PYTHON%%|${PYTHON_CMD}|' ${WRKSRC}/drpython.lin

pre-build:
	@(cd ${WRKSRC}/docsrc && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} html)
	@(cd ${WRKSRC}/docsrc/_build/html && ${CP} -f *.html *.js \
		${WRKSRC}/documentation)

post-build:
	@${ECHO_CMD} '#!/bin/sh' > ${WRKDIR}/drpython.sh
.if ${OPSYS} == FreeBSD && ${CHOSEN_COMPILER_TYPE} == gcc
	@${ECHO_CMD} 'LD_LIBRARY_PATH="${LOCALBASE}/lib/${CC}:$$LD_LIBRARY_PATH"' \
		>> ${WRKDIR}/drpython.sh
	@${ECHO_CMD} 'export LD_LIBRARY_PATH' >> ${WRKDIR}/drpython.sh
.endif
	@${ECHO_CMD} 'exec ${PYTHON_CMD} -m drpython.drpython' >> ${WRKDIR}/drpython.sh

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/drpython.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
