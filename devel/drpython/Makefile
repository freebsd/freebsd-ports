# Created by: vsevolod
# $FreeBSD$

PORTNAME=	drpython
PORTVERSION=	3.11.3
PORTREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/DrPython%20%283.x%29/${PORTVERSION}
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}
DISTNAME=	DrPython_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Highly customizable cross-platform ide to aid programming in Python

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/DrPython

USES=		zip
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_PKGNAME=	DrPython
USE_WX=		2.6+
WX_COMPS=	python:lib

DESKTOP_ENTRIES=	"DrPython" "Python editor and IDE" \
			"${PYTHONPREFIX_SITELIBDIR}/drpython/bitmaps/drpython.png" \
			"drpython" "Development;IDE;" "false"

PLIST_FILES=	bin/drpython

NO_STAGE=	yes
post-install:
	@${ECHO_CMD} '#!/bin/sh' > ${WRKDIR}/drpython.sh
	@${ECHO_CMD} 'exec ${PYTHON_CMD} -m drpython.drpython' >> ${WRKDIR}/drpython.sh
	${INSTALL_SCRIPT} ${WRKDIR}/drpython.sh ${PREFIX}/bin/drpython

.include <bsd.port.mk>
