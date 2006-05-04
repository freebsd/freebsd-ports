# New ports collection makefile for:	m17n-lib
# Date created:				29 May 2004
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	m17n-lib
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.m17n.org/m17n-lib/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for the multilingual text handling

BUILD_DEPENDS=	${LOCALBASE}/share/m17n/mdb.dir:${PORTSDIR}/devel/m17n-db
LIB_DEPENDS=	fribidi.0:${PORTSDIR}/converters/fribidi \
		gd.4:${PORTSDIR}/graphics/gd \
		otf.0:${PORTSDIR}/print/libotf \
		Xft.2:${PORTSDIR}/x11-fonts/libXft
RUN_DEPENDS=	${LOCALBASE}/share/m17n/mdb.dir:${PORTSDIR}/devel/m17n-db

USE_XLIB=	yes
USE_GNOME=	gnometarget libxml2 pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

OPTIONS=	ANTHY	"With Anthy support" off \
		ISPELL	"With Ispell support" off

.include <bsd.port.pre.mk>

.if defined(WITH_ANTHY)
LIB_DEPENDS+=	anthy.1:${PORTSDIR}/japanese/anthy
.else
CONFIGURE_ENV+=	ac_cv_lib_anthydic_anthy_init_sessions=no
.endif

.if defined(WITH_ISPELL)
BUILD_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.else
CONFIGURE_ENV+=	HAVE_ISPELL=no
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|g ; \
		 s|-ldl||g'

.include <bsd.port.post.mk>
