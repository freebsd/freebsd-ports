# New ports collection makefile for:	py-gdchart
# Date created:		18 June 2001
# Whom:			Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$

PORTNAME=	gdchart
PORTVERSION=	0.6
CATEGORIES=	graphics python
MASTER_SITES=	http://athani.pair.com/msteed/software/gdchart/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	perky@python.or.kr

BUILD_DEPENDS=	${LOCALBASE}/lib/libgdchart.a:${PORTSDIR}/graphics/gdchart

USE_PYTHON=	yes
USE_GMAKE=	yes
MAKE_ENV=	GD_INCLUDE=${LOCALBASE}/include/gd \
		GDCHART_INCLUDE=${LOCALBASE}/include \
		PYTHON_INCLUDE=${PYTHON_INCLUDEDIR} \
		LOCALBASE=${LOCALBASE}
PLIST_SUB=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g} \
		EXAMPLE_DIR=${EXAMPLE_DIR:S/^${LOCALBASE}\///g}
MODULE_FILES=	chart.py gdchart.so
EXAMPLE_FILES=	test.html test.py CHANGES
EXAMPLE_DIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

do-install:
.for file in ${MODULE_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PYTHON_SITELIBDIR}
.endfor
.if !defined(NO_PORTDOCS)
	${MKDIR} ${EXAMPLE_DIR}
.for file in ${EXAMPLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${EXAMPLE_DIR}
.endfor
.endif

.include <bsd.port.mk>
