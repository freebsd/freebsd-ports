# New ports collection makefile for:	Togl
# Date created:		Wed Aug 18 18:49:17 EDT 1999
# Whom:			Randall Hopper <aa8vb@ipass.net>
#
# $FreeBSD$
#

PORTNAME=	togl
PORTVERSION=	1.5
CATEGORIES=	graphics tk82
MASTER_SITES=	ftp://ftp.mesa3d.org/mesa/misc/ \
		ftp://ftp.cs.umd.edu/pub/faculty/bederson/
DISTNAME=	Togl-${PORTVERSION}

MAINTAINER=	aa8vb@ipass.net

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82 \
		tcl82.1:${PORTSDIR}/lang/tcl82

USE_MESA=	yes
ALL_TARGET=	default

TOGL_INSTDIR=	${PREFIX}/lib/tk8.2/${DISTNAME}

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${TOGL_INSTDIR}
	${INSTALL_DATA} ${WRKSRC}/libtogl.so.1.3 ${TOGL_INSTDIR}/Togl.so
	${INSTALL_DATA} ${WRKSRC}/togl.h ${TOGL_INSTDIR}
	${INSTALL_DATA} ${WRKSRC}/togl.o ${TOGL_INSTDIR}
	${ECHO} 'package ifneeded Togl 1.5 [list load [file join $$dir Togl.so]]'\
	  > ${PREFIX}/lib/tk8.2/${DISTNAME}/pkgIndex.tcl

.include <bsd.port.post.mk>
