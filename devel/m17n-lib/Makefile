# New ports collection makefile for:	m17n-lib
# Date created:				29 May 2004
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	m17n-lib
PORTVERSION=	1.1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.m17n.org/m17n-lib/download/

MAINTAINER=	fuyuki@hadaly.org
COMMENT=	A library for the multilingual text handling

LIB_DEPENDS=	fribidi.0:${PORTSDIR}/converters/fribidi \
		otf.0:${PORTSDIR}/print/libotf \
		Xft.2:${PORTSDIR}/x11-fonts/libXft \
		gd.4:${PORTSDIR}/graphics/gd
BUILD_DEPENDS=	${LOCALBASE}/share/m17n/mdb.dir:${PORTSDIR}/devel/m17n-db
RUN_DEPENDS=	${LOCALBASE}/share/m17n/mdb.dir:${PORTSDIR}/devel/m17n-db

USE_REINPLACE=	yes
USE_XLIB=	yes
USE_GNOME=	libxml2
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

OPTIONS=	ANTHY	"With Anthy support" off \
		ISPELL	"With Ispell support" off

.include <bsd.port.pre.mk>

.ifdef WITH_ANTHY
LIB_DEPENDS+=	anthy.1:${PORTSDIR}/japanese/anthy
.else
CONFIGURE_ENV+=	ac_cv_lib_anthydic_anthy_init_sessions=no
.endif

.ifdef WITH_ISPELL
BUILD_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.else
CONFIGURE_ENV+=	HAVE_ISPELL=no
.endif

post-patch:
	${REINPLACE_CMD} -e 's/-ldl//' ${WRKSRC}/*/Makefile.in

.include <bsd.port.post.mk>
