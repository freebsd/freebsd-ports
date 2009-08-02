# New ports collection makefile for:	m17n-lib
# Date created:				29 May 2004
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	m17n-lib
PORTVERSION=	1.5.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.m17n.org/m17n-lib-download/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	A library for the multilingual text handling

BUILD_DEPENDS=	m17n-db>=1.5.4:${PORTSDIR}/devel/m17n-db
LIB_DEPENDS=	fribidi.0:${PORTSDIR}/converters/fribidi \
		gd.4:${PORTSDIR}/graphics/gd \
		otf.0:${PORTSDIR}/print/libotf
RUN_DEPENDS=	m17n-db>=1.5.4:${PORTSDIR}/devel/m17n-db

MAKE_JOBS_UNSAFE=	yes

USE_XORG=	xaw xft xt
USE_GNOME=	gnometarget libxml2 pkgconfig
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
USE_LDCONFIG=	yes

OPTIONS=	ANTHY	"With Anthy support" off \
		ISPELL	"With Ispell support" off \
		THAI	"With libThai support" off

.include <bsd.port.pre.mk>

.if defined(WITH_ANTHY)
LIB_DEPENDS+=	anthy.1:${PORTSDIR}/japanese/anthy
.else
CONFIGURE_ARGS+=	--without-anthy
.endif

.if defined(WITH_ISPELL)
BUILD_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.else
CONFIGURE_ENV+=	HAVE_ISPELL=no
.endif

.if defined(WITH_THAI)
LIB_DEPENDS+=	thai.0:${PORTSDIR}/devel/libthai
.else
CONFIGURE_ARGS+=	--without-libthai
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|g ; \
		 s|-ldl||g'

.include <bsd.port.post.mk>
