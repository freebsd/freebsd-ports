# New ports collection makefile for:	Togl
# Date created:		Wed Aug 18 18:49:17 EDT 1999
# Whom:			Randall Hopper <aa8vb@ipass.net>
#
# $FreeBSD$
#

PORTNAME=	togl
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	graphics tk84
MASTER_SITES=	ftp://ftp.mesa3d.org/mesa/misc/ \
		ftp://ftp.cs.umd.edu/pub/faculty/bederson/
DISTNAME=	Togl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Tk OpenGL widget

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84 \
		tcl84.1:${PORTSDIR}/lang/tcl84

USE_MESA=	yes
ALL_TARGET=	default
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

TOGL_INSTDIR=	${PREFIX}/lib/tk8.4/${DISTNAME}

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${TOGL_INSTDIR}
	${INSTALL_DATA} ${WRKSRC}/libtogl.so.1.3 ${TOGL_INSTDIR}/Togl.so
	${INSTALL_DATA} ${WRKSRC}/togl.h ${TOGL_INSTDIR}
	${INSTALL_DATA} ${WRKSRC}/togl.o ${TOGL_INSTDIR}
	${ECHO} 'package ifneeded Togl 1.5 [list load [file join $$dir Togl.so]]'\
	  > ${PREFIX}/lib/tk8.4/${DISTNAME}/pkgIndex.tcl

.include <bsd.port.post.mk>
