# New ports collection makefile for:	OpenEXR
# Date created:				2003/01/26
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	OpenEXR
PORTVERSION=	1.4.0
PORTREVISION=	0
DISTNAME=	${PORTNAME:L}-${PORTVERSION}${DISTVERSIONSUFFIX}
DISTVERSIONSUFFIX=a
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	openexr

MAINTAINER=	nork@FreeBSD.org
COMMENT=	A high dynamic-range (HDR) image file format

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	YES
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
INSTALLS_SHLIB=	YES

EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}-${PORTVERSION}

CONFIGURE_ENV+=	PTHREAD_LIBS=${PTHREAD_LIBS} \
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS}

WRKSRC=		${WRKDIR}/${PORTNAME:L}-${PORTVERSION}

.include <bsd.port.pre.mk>

#.if !defined(WITHOUT_X11) && defined(WITH_FLTK)
#CONFIGURE_ARGS+=--with-fltk-config=${X11BASE}/bin/fltk-config
#CFLAGS+=	${PTHREAD_CFLAGS}
#LDFLAGS+=	${PTHREAD_LIBS}
#PLIST_SUB+=	WITH_FLTK=
#LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk-threads \
#		glut.4:${PORTSDIR}/graphics/libglut
#.else
CONFIGURE_ARGS+=--with-fltk-config=${FALSE} --without-x
PLIST_SUB+=	WITH_FLTK="@comment "
#.endif

.include <bsd.port.post.mk>
