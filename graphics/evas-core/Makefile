# New ports collection makefile for:	evas-core
# Date created:		15 September 2007
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	core
DISTVERSION=	1.0.1
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2011-05-25/base/
PKGNAMEPREFIX=	evas-
DISTNAME=	evas-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A hardware accelerated canvas API (core library)

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

LICENSE=	BSD
DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack pkgconfig
USE_EFL=	librt_hack libtool_hack
DATADIR=	${PREFIX}/share/evas

.include "Makefile.inc"

OPTIONS=	FONTCONFIG	"Enable fontconfig support" on \
		FRIBIDI	"Enable bidirectional text support" on \
		EET		"Enable EET font loader" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_FONTCONFIG)
CONFIGURE_ARGS+=	--enable-fontconfig
LIB_DEPENDS+=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
.else
CONFIGURE_ARGS+=	--disable-fontconfig
.endif

.if !defined(WITHOUT_FRIBIDI)
CONFIGURE_ARGS+=	--enable-fribidi 
LIB_DEPENDS+=		fribidi.3:${PORTSDIR}/converters/fribidi
.else
CONFIGURE_ARGS+=	--disable-fribidi 
.endif

.if !defined(WITHOUT_EET)
CONFIGURE_ARGS+=	--enable-font-loader-eet
USE_EFL+=	eet
.else
CONFIGURE_ARGS+=	--disable-font-loader-eet
.endif

.include <bsd.port.post.mk>
