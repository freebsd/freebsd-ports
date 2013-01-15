# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	core
PORTVERSION=	1.7.5
PORTREVISION=	1
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.fr/releases/ \
		LOCAL/gblach/e17/
PKGNAMEPREFIX=	evas-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	A hardware accelerated canvas API (core library)

LICENSE=	BSD

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GCC=	any
USE_EFL=	librt_hack libtool_hack
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes
DATADIR=	${PREFIX}/share/evas
EXAMPLESDIR=	${PREFIX}/share/examples/evas

.include "Makefile.inc"

OPTIONS_DEFINE=	EET FONTCONFIG FRIBIDI
OPTIONS_DEFAULT=EET FONTCONFIG FRIBIDI
EET_DESC=	EET font loader
FRIBIDI_DESC=	Bidirectional text support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFONTCONFIG}
LIB_DEPENDS+=	fontconfig:${PORTSDIR}/x11-fonts/fontconfig
CONFIGURE_ARGS+=--enable-fontconfig
.else
CONFIGURE_ARGS+=--disable-fontconfig
.endif

.if ${PORT_OPTIONS:MFRIBIDI}
LIB_DEPENDS+=	fribidi:${PORTSDIR}/converters/fribidi
CONFIGURE_ARGS+=--enable-fribidi
.else
CONFIGURE_ARGS+=--disable-fribidi
.endif

.if ${PORT_OPTIONS:MEET}
USE_EFL+=	eet
CONFIGURE_ARGS+=--enable-font-loader-eet
.else
CONFIGURE_ARGS+=--disable-font-loader-eet
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
CONFIGURE_ARGS+=--enable-install-examples
.else
CONFIGURE_ARGS+=--disable-install-examples
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|= \$$(datadir)/\$$(PACKAGE)/examples|= $$(datadir)/examples/$$(PACKAGE)|' \
		${WRKSRC}/src/examples/Makefile.in

post-install:
.if empty(PORT_OPTIONS:MEXAMPLES)
	@${RMDIR} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
