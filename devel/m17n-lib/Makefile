# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	m17n-lib
PORTVERSION=	1.8.0
PORTREVISION=	1
CATEGORIES=	devel textproc
MASTER_SITES=	SAVANNAH/m17n

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Library for the multilingual text handling

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	m17n-db>=1.8.0:devel/m17n-db
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libgd.so:graphics/gd \
		libotf.so:print/libotf
RUN_DEPENDS=	m17n-db>=1.8.0:devel/m17n-db

MAKE_JOBS_UNSAFE=	yes

USES=		autoreconf bison gettext-tools gnome libtool pathfix pkgconfig \
		xorg
USE_XORG=	ice sm x11 xaw xft xmu xrender xt
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-nls

OPTIONS_DEFINE=	ANTHY ISPELL THAI

ANTHY_DESC=	Kana-Kanji conversion support via Anthy
ISPELL_DESC=	Spell checking support via Ispell
THAI_DESC=	Thai language support via libThai

ANTHY_LIB_DEPENDS=	libanthy.so:japanese/anthy
ANTHY_CONFIGURE_OFF=	--without-anthy

ISPELL_BUILD_DEPENDS=	ispell:textproc/aspell-ispell
ISPELL_RUN_DEPENDS=	ispell:textproc/aspell-ispell
ISPELL_CONFIGURE_OFF=	HAVE_ISPELL=no

THAI_LIB_DEPENDS=	libthai.so:devel/libthai
THAI_CONFIGURE_OFF=	--without-libthai

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.am" | ${XARGS} ${REINPLACE_CMD} -e 's|-ldl||g'

.include <bsd.port.mk>
