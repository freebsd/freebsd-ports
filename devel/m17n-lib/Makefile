# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	m17n-lib
PORTVERSION=	1.6.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.m17n.org/m17n-lib-download/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Library for the multilingual text handling

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison \
		m17n-db>=1.6.2:${PORTSDIR}/devel/m17n-db
LIB_DEPENDS=	fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		freetype:${PORTSDIR}/print/freetype2 \
		fribidi:${PORTSDIR}/converters/fribidi \
		gd:${PORTSDIR}/graphics/gd \
		otf:${PORTSDIR}/print/libotf
RUN_DEPENDS=	m17n-db>=1.6.2:${PORTSDIR}/devel/m17n-db

MAKE_JOBS_UNSAFE=	yes

USE_XORG=	ice sm x11 xaw xft xt
USE_GNOME=	libxml2 pkgconfig
USE_AUTOTOOLS=	autoconf libtool
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-nls

OPTIONS_DEFINE=	ANTHY ISPELL THAI

ANTHY_DESC=	Kana-Kanji conversion support via Anthy
ISPELL_DESC=	Spell checking support via Ispell
THAI_DESC=	Thai language support via libThai

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MANTHY}
LIB_DEPENDS+=	anthy:${PORTSDIR}/japanese/anthy
.else
CONFIGURE_ARGS+=	--without-anthy
.endif

.if ${PORT_OPTIONS:MISPELL}
BUILD_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.else
CONFIGURE_ENV+=	HAVE_ISPELL=no
.endif

.if ${PORT_OPTIONS:MTHAI}
LIB_DEPENDS+=	thai:${PORTSDIR}/devel/libthai
.else
CONFIGURE_ARGS+=	--without-libthai
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|g ; \
		 s|-ldl||g'

.include <bsd.port.mk>
