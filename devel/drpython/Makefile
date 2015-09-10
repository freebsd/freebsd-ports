# Created by: vsevolod
# $FreeBSD$

PORTNAME=	drpython
PORTVERSION=	3.11.4
PORTREVISION=	4
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

USES=		python zip
USE_PYTHON=	distutils autoplist
USE_WX=		3.0+
WX_COMPS=	python:lib

PLIST_FILES=	bin/drpython

DESKTOP_ENTRIES="DrPython" "Python editor and IDE" \
		"${PYTHONPREFIX_SITELIBDIR}/drpython/bitmaps/drpython.png" \
		"drpython" "Development;IDE;" ""

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
	@${ECHO_CMD} 'exec ${PYTHON_CMD} -m drpython.drpython' >> ${WRKDIR}/drpython.sh

post-install:
	(cd ${WRKDIR} && ${INSTALL_SCRIPT} drpython.sh \
		${STAGEDIR}${PREFIX}/bin/drpython)

.include <bsd.port.mk>
