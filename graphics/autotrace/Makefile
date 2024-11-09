PORTNAME=	autotrace
DISTVERSION=	0.31.10
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/autotrace/autotrace/commit/
PATCHFILES=	eeeb813a416ff309804f6833729fab20d036e667.patch:-p1 \
		f436324241f4855325e64c6de0fb5be848a300f5.patch:-p1 \
		a26cfe0039f00012613edbe7cc5c58b623b3ea48.patch:-p1 \
		b32c25d16dadf85e6236b13aaf10edae52d810f4.patch:-p1 \
		a74b683a6bfeceeda8c4086a3eb559a98e950c95.patch:-p1 \
		3b148a17199ad730995614b143cceb6a9987cf07.patch:-p1 \
		bc1bcc06790b81db73c3bafab94c47f47a2ac8e8.patch:-p1 \
		1a1b29e4e041098d920a3a1f2fd237bca98eecda.patch:-p1 \
		190f18251b8fe9a361cd8154f2f746855472ffed.patch:-p1

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Convert bitmap to vector graphics
WWW=		https://github.com/autotrace/autotrace

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libpng.so:graphics/png

USES=		autoreconf:2.69 cpe gettext-tools gettext-runtime gmake gnome libtool pathfix pkgconfig
CPE_VENDOR=	autotrace_project
USE_GNOME=	glib20 intltool
USE_LDCONFIG=	yes

USE_GITHUB=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CONFIGURE_ENV=	ac_cv_header_ming_h=no
CONFIGURE_ARGS=	--disable-nls \
		--disable-static

OPTIONS_DEFINE=	IMAGEMAGICK PSTOEDIT
OPTIONS_DEFAULT=IMAGEMAGICK

PSTOEDIT_DESC=	Convert postscript to other formats

IMAGEMAGICK_USES=		magick:7
IMAGEMAGICK_CONFIGURE_OFF=	--without-magick

PSTOEDIT_LIB_DEPENDS=	libpstoedit.so:graphics/pstoedit
PSTOEDIT_CONFIGURE_OFF=	--without-pstoedit

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/locale

.include <bsd.port.mk>
