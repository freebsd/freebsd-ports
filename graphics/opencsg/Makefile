# New ports collection makefile for:	opencsg
# Date created:				17 August 2011
# Whom:					Michael Reifenberger <mr@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	opencsg
PORTVERSION=	1.3.1
#PORTREVISION=	0
CATEGORIES=	graphics
MASTER_SITES=	http://www.opencsg.org/
DISTNAME=	OpenCSG-${PORTVERSION}

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Constructive Solid Geometry rendering library

USE_GL=		glew
WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_QT_VER=     4
QT_COMPONENTS=  qmake_build
PLIST_SUB=      PORTVERSION=${PORTVERSION}
#MAKE_JOBS_UNSAFE=yes

do-configure:
	cd ${WRKSRC} && ${QMAKE} src.pro

do-install:
	${INSTALL_LIB} ${WRKDIR}/${DISTNAME}/lib/libopencsg.so.${PORTVERSION} \
		${PREFIX}/lib
	${LN} -sf libopencsg.so.${PORTVERSION} ${PREFIX}/lib/libopencsg.so.1
	${LN} -sf libopencsg.so.${PORTVERSION} ${PREFIX}/lib/libopencsg.so
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/include/opencsg.h ${PREFIX}/include

.include <bsd.port.mk>
