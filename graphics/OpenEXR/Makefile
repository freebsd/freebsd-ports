# New ports collection makefile for:	OpenEXR
# Date created:				2003/01/26
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	OpenEXR
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	http://savannah.nongnu.org/download/openexr/${PORTNAME}.pkg/${PORTVERSION}/

MAINTAINER=	nork@FreeBSD.org

USE_GCC=	3.1
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
INSTALLS_SHLIB=	YES

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_X11) && (defined(WITH_FLTK) || defined(WITH_FLTK_XUNICODE))
.if defined(WITH_FLTK_XUNICODE)
LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk-xunicode
.else
LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk
.endif
USE_MESA=	YES
CONFIGURE_ARGS+=--with-fltk-prefix=${X11BASE}
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LDFLAGS}
PLIST_SUB+=	WITH_FLTK=
.if ${OSVERSION} < 500035
pre-everything::
	@${ECHO_CMD} ===================================================
	@${ECHO_CMD} Please install x11-toolkits/fltk* with USE_GCC=3.1.
	@${ECHO_CMD} ===================================================
.endif
.else
CONFIGURE_ARGS+=--with-fltk-prefix=DUMMY
PLIST_SUB+=	WITH_FLTK="@comment "
.endif

.ifdef WITHOUT_X11
CONFIGURE_ARGS+=--without-x
.endif

.include <bsd.port.post.mk>
