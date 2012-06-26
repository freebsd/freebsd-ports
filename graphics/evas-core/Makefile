# New ports collection makefile for:	evas-core
# Date created:		15 September 2007
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	core
DISTVERSION=	1.1.0
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2011-12-02/base/
PKGNAMEPREFIX=	evas-
DISTNAME=	evas-${DISTVERSION}

MAINTAINER=	magik@roorback.net
COMMENT=	A hardware accelerated canvas API (core library)

LICENSE=	BSD

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack pkgconfig
USE_EFL=	librt_hack libtool_hack
DATADIR=	${PREFIX}/share/evas

.include "Makefile.inc"

OPTIONS=	FONTCONFIG	"Enable fontconfig support" on \
		FRIBIDI		"Enable bidirectional text support" on \
		EET		"Enable EET font loader" on

EXAMPLESDIR=	${PREFIX}/share/examples/evas

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

.if !defined(NOPORTEXAMPLES)
CONFIGURE_ARGS+=	--enable-install-examples
.else
CONFIGURE_ARGS+=	--disable-install-examples
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|= \$$(datadir)/\$$(PACKAGE)/examples|= $$(datadir)/examples/$$(PACKAGE)|' \
		${WRKSRC}/src/examples/Makefile.in

post-install:
.if defined(NOPORTEXAMPLES)
	@${RMDIR} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
