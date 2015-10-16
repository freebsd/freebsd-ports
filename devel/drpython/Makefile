# Created by: vsevolod
# $FreeBSD$

PORTNAME=	drpython
PORTVERSION=	3.11.4
PORTREVISION=	5
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/DrPython%20%283.x%29/${PORTVERSION}
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}
DISTNAME=	DrPython_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Highly customizable cross-platform ide to aid programming in Python

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:${PORTSDIR}/textproc/py-sphinx
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		compiler:c++11-lib python zip
USE_PYTHON=	distutils autoplist
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

pre-build:
	@(cd ${WRKSRC}/docsrc && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} html)
	@(cd ${WRKSRC}/docsrc/_build/html && ${CP} -f *.html *.js \
		${WRKSRC}/documentation)

post-build:
	@${MKDIR} ${WRKDIR}/wrappers
	@${ECHO_CMD} -n \
		>> ${WRKDIR}/wrappers/drpython
	@${ECHO_CMD} '#!/bin/sh' \
		>> ${WRKDIR}/wrappers/drpython
.if ${OPSYS} == FreeBSD && ${CHOSEN_COMPILER_TYPE} == gcc
	@${ECHO_CMD} 'LD_LIBRARY_PATH="${LOCALBASE}/lib/${CC}:$$LD_LIBRARY_PATH"' \
		>> ${WRKDIR}/wrappers/drpython
	@${ECHO_CMD} 'export LD_LIBRARY_PATH' \
		>> ${WRKDIR}/wrappers/drpython
	@${ECHO_CMD} \
		>> ${WRKDIR}/wrappers/drpython
.endif
	@${ECHO_CMD} 'exec ${PYTHON_CMD} -m drpython.drpython' \
		>> ${WRKDIR}/wrappers/drpython

post-install:
	(cd ${WRKDIR}/wrappers && ${INSTALL_SCRIPT} drpython \
		${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.post.mk>
