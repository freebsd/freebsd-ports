# New ports collection makefile for:   GraphicsMagick
# Date created:        25 july 2005
# Whom:                Ron van Daal
#
# $FreeBSD$
#

PORTNAME=	GraphicsMagick
PORTVERSION=	1.1.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.graphicsmagick.org/pub/GraphicsMagick/
MASTER_SITE_SUBDIR=	${PORTNAME:L}

MAINTAINER=	ronvdaal@n1x.nl
COMMENT=	Fast image processing tools based on ImageMagick

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2	\
		jbig:${PORTSDIR}/graphics/jbigkit	\
		wmf:${PORTSDIR}/graphics/libwmf	\
		xml2:${PORTSDIR}/textproc/libxml2
OTHERGRAPHICS=	jasper jpeg lcms png tiff
LIB_DEPENDS+=	${OTHERGRAPHICS:C|(.+)|\1:${PORTSDIR}/graphics/\1|}
OPTIONS=	Q8BIT "Use 8-bit pixels (speed) instead of 16 (quality)" off

# Use libfpx only on i386. On other systems it does not seem to work :-(
OPTIONS+=	FPX "Build FPX backend -- broken on non-i386 systems" \
		    ${ARCH:S,i386,on,:C,^[^o].*,off,}

USE_BZIP2=	yes
USE_GHOSTSCRIPT=yes
USE_LIBTOOL_VER=15

MAN1=	GraphicsMagick++-config.1 \
	GraphicsMagick-config.1 \
	GraphicsMagickWand-config.1 \
	gm.1
MAN4=	miff.4
MAN5=	quantize.5

.ifndef WINDOWS_FONT_DIR
# Use fonts installed by x11-fonts/webfonts by default
WINDOWS_FONT_DIR=${X11BASE}/lib/X11/webfonts
.endif

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--without-perl --with-windows-font-dir=${WINDOWS_FONT_DIR} \
		--enable-shared --enable-static --without-threads
INSTALLS_SHLIB=	yes

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install-data-html
.endif
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"       \
	LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

# Perl and Tcl APIs will be installed by separate ports
PLIST_SUB+=	WITH_PERL="@comment "

.if defined(WITHOUT_X11)
PKGNAMESUFFIX+=	-nox11
CONFIGURE_ARGS+=--without-x
.endif

.if defined(WITH_FPX)
LIB_DEPENDS+=	fpx:${PORTSDIR}/graphics/libfpx
.else
CONFIGURE_ARGS+=--without-fpx
.endif

.if defined(WITH_Q8BIT) || defined(WITHOUT_GRAPHICSMAGICK_16BIT_PIXEL)
CONFIGURE_ARGS+=	--with-quantum-depth=8
PLIST_SUB+=		Q=8
.else
CONFIGURE_ARGS+=	--with-quantum-depth=16
PLIST_SUB+=		Q=16
.endif

post-build test:
	cd ${WRKSRC}/tests && ${MAKE} check

.include <bsd.port.post.mk>
