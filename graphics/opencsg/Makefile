# Created by: Michael Reifenberger <mr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opencsg
PORTVERSION=	1.4.2
#PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.opencsg.org/
DISTNAME=	OpenCSG-${PORTVERSION}

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Constructive Solid Geometry rendering library

LICENSE=	GPLv2

USES=		qmake:outsource
USE_GL=		gl glew
USE_QT4=	corelib gui
WRKSRC=		${WRKDIR}/${DISTNAME}/src
PLIST_SUB=      PORTVERSION=${PORTVERSION}

do-install:
	${INSTALL_LIB} ${WRKDIR}/lib/libopencsg.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib
	${LN} -sf libopencsg.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libopencsg.so.1
	${LN} -sf libopencsg.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libopencsg.so
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/include/opencsg.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
