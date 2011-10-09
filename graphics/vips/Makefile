# New ports collection makefile for:	vips
# Date created:		19 December 2003
# Whom:			Lev Serebryakov <lev@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vips
PORTVERSION=	7.26.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.vips.ecs.soton.ac.uk/supported/${PORTVERSION:R}/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Free image processing system

OPTIONS+=	LIBOIL	"Use liboil for CPU-optimized primitives" on
OPTIONS+=	PYTHON	"Create Python bindings" ${PYPRESENT}

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	fftw3:${PORTSDIR}/math/fftw3 \
		jpeg:${PORTSDIR}/graphics/jpeg \
		exif:${PORTSDIR}/graphics/libexif	\
		tiff:${PORTSDIR}/graphics/tiff \
		GraphicsMagick:${PORTSDIR}/graphics/GraphicsMagick \
		IlmImf:${PORTSDIR}/graphics/OpenEXR \
		orc-0:${PORTSDIR}/devel/orc	\
		png:${PORTSDIR}/graphics/png \
		matio:${PORTSDIR}/math/matio	\
		lcms:${PORTSDIR}/graphics/lcms

PYPRESENT!=	which python > /dev/null && echo on || echo off
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_PERL5_BUILD=yes
USE_GNOME=	gnomehack glib20 pkgconfig pango libxml2
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

post-configure:
	${REINPLACE_CMD} -Ee 's,^(G?MSGFMT = *)$$,\1${LOCALBASE}/bin/msgfmt,g' \
		${WRKSRC}/po/Makefile

# Don't extract doc/ subdirectory - the simplest way:
.ifdef NOPORTDOCS
EXTRACT_AFTER_ARGS=	| ${TAR} -xpf - --exclude doc
EXTRA_PATCHES=	${FILESDIR}/nodoc-patch
.endif
PLIST_SUB+=	VERSION=${PORTVERSION:R}

CONFIGURE_ENV+=	MAGICK_CFLAGS="-I${LOCALBASE}/include/GraphicsMagick"
CONFIGURE_ARGS+=--without-x --mandir=${PREFIX}/man --with-magickpackage=GraphicsMagick
CONFIGURE_ARGS+=--without-v4l
.for p in tiff jpeg zip png
CONFIGURE_ARGS+=--with-$p-includes=${LOCALBASE}/include
CONFIGURE_ARGS+=--with-$p-libraries=${LOCALBASE}/lib
.endfor

.include "Makefile.man"

.include <bsd.port.options.mk>
.if defined(WITH_PYTHON)
USE_PYTHON=	yes
PLIST_SUB+=	PY=""
.else
CONFIGURE_ARGS=	--without-python
PLIST_SUB+=	PY="@comment "
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_LIBOIL)
LIB_DEPENDS+=	oil:${PORTSDIR}/devel/liboil
.else
CONFIGURE_ARGS+=	--without-liboil
.endif

.include <bsd.port.post.mk>
