# Created by: vsevolod
# $FreeBSD$

PORTNAME=	drpython
PORTVERSION=	3.11.3
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/DrPython%20%283.x%29/${PORTVERSION}
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}
DISTNAME=	DrPython_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Highly customizable cross-platform ide to aid programming in Python

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/DrPython

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	DrPython
USE_WX=		2.6+
WX_COMPS=	python:lib

DESKTOP_ENTRIES=	"DrPython" "Python editor and IDE" \
			"${PYTHONPREFIX_SITELIBDIR}/drpython/bitmaps/drpython.png" \
			"drpython" "Development;IDE;" "false"

NO_STAGE=	yes
post-install:
	@${ECHO_CMD} '#!/bin/sh' > ${WRKDIR}/drpython.sh
	@${ECHO_CMD} '(cd ${PYTHONPREFIX_SITELIBDIR}/drpython && ${PYTHON_CMD} drpython.py)' >> ${WRKDIR}/drpython.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/drpython.sh ${PREFIX}/bin/drpython

.include <bsd.port.mk>
