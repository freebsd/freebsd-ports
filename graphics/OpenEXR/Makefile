# New ports collection makefile for:	OpenEXR
# Date created:				2003/01/26
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	OpenEXR
PORTVERSION=	1.0.5
PORTREVISION=	3
CATEGORIES=	graphics devel
MASTER_SITES=	http://savannah.nongnu.org/download/openexr/${PORTNAME}.pkg/${PORTVERSION}/

MAINTAINER=	nork@FreeBSD.org
COMMENT=	OpenEXR, a high dynamic-range (HDR) image file format developed by ILM

USE_GCC=	3.1+
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
INSTALLS_SHLIB=	YES

EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if defined(USE_GCC) && ${USE_GCC} == 3.1+ && ${OSVERSION} < 500035
CC=		gcc31
CXX=		g++31
BUILD_DEPENDS+=	gcc31:${PORTSDIR}/lang/gcc31
MAKE_ENV+=	CC=${CC} CXX=${CXX}
.endif

.if !defined(WITHOUT_X11) && defined(WITH_FLTK)
CONFIGURE_ARGS+=--with-fltk-config=${X11BASE}/bin/fltk-config
USE_MESA=	YES
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LDFLAGS}
PLIST_SUB+=	WITH_FLTK=
LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk
.if ${OSVERSION} < 500035
pre-everything::
	@${ECHO_CMD} ===================================================
	@${ECHO_CMD} Please install x11-toolkits/fltk* with USE_GCC=3.1.
	@${ECHO_CMD} ===================================================
.endif
.else
CONFIGURE_ARGS+=--with-fltk-config=${FALSE} --without-x
PLIST_SUB+=	WITH_FLTK="@comment "
.endif

.include <bsd.port.post.mk>
