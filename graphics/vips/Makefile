# Created by: Lev Serebryakov <lev@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vips
PORTVERSION=	7.26.3
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://www.vips.ecs.soton.ac.uk/supported/${PORTVERSION:R}/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Free image processing system

OPTIONS_DEFINE=	LIBOIL PYTHON
OPTIONS_DEFAULT=	LIBOIL
LIBOIL_DESC=	Use leiboil for CPU-optimized primitives
PYTHON_DESC=	Create Python bindings

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	fftw3:${PORTSDIR}/math/fftw3 \
		jpeg:${PORTSDIR}/graphics/jpeg \
		exif:${PORTSDIR}/graphics/libexif	\
		tiff:${PORTSDIR}/graphics/tiff \
		GraphicsMagick:${PORTSDIR}/graphics/GraphicsMagick \
		IlmImf:${PORTSDIR}/graphics/OpenEXR \
		orc-0:${PORTSDIR}/devel/orc	\
		png15:${PORTSDIR}/graphics/png \
		matio:${PORTSDIR}/math/matio	\
		lcms:${PORTSDIR}/graphics/lcms

PYPRESENT!=	which python > /dev/null && echo on || echo off
.if ${PYPRESENT} == on
OPTIONS_DEFAULT+=	PYTHON
.endif
USES=		gettext gmake perl5 pkgconfig
USE_PERL5=	build
USE_GNOME=	gnomehack glib20 pango libxml2
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

NO_STAGE=	yes
post-configure:
	${REINPLACE_CMD} -Ee 's,^(G?MSGFMT = *)$$,\1${LOCALBASE}/bin/msgfmt,g' \
		${WRKSRC}/po/Makefile

.include <bsd.port.options.mk>
# Don't extract doc/ subdirectory - the simplest way:
.if ! ${PORT_OPTIONS:MDOCS}
EXTRACT_AFTER_ARGS=	--exclude doc
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

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
PLIST_SUB+=	PY=""
.else
CONFIGURE_ARGS=	--without-python
PLIST_SUB+=	PY="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" && ${OSVERSION} > 900000
BROKEN=		Does not compile on sparc64-9
.endif

.if ${PORT_OPTIONS:MLIBOIL}
LIB_DEPENDS+=	oil:${PORTSDIR}/devel/liboil
.else
CONFIGURE_ARGS+=	--without-liboil
.endif

.include <bsd.port.post.mk>
