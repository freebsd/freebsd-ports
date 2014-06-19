# Created by: Lev Serebryakov <lev@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vips
PORTVERSION=	7.26.3
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	http://www.vips.ecs.soton.ac.uk/supported/${PORTVERSION:R}/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Free image processing system

OPTIONS_DEFINE=	LIBOIL PYTHON DOCS
OPTIONS_DEFAULT=	LIBOIL
LIBOIL_DESC=	Use liboil for CPU-optimized primitives
PYTHON_DESC=	Create Python bindings

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3 \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libexif.so:${PORTSDIR}/graphics/libexif	\
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libGraphicsMagick.so:${PORTSDIR}/graphics/GraphicsMagick \
		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		liborc-0.4.so:${PORTSDIR}/devel/orc	\
		libpng15.so:${PORTSDIR}/graphics/png \
		libmatio.so:${PORTSDIR}/math/matio	\
		liblcms.so:${PORTSDIR}/graphics/lcms

PYPRESENT!=	which python > /dev/null && echo on || echo off
.if ${PYPRESENT} == on
OPTIONS_DEFAULT+=	PYTHON
.endif
USES=		gettext gmake libtool pathfix perl5 pkgconfig shebangfix
USE_PERL5=	build
SHEBANG_FILES=	tools/vips-${PORTVERSION:R}
USE_GNOME=	glib20 pango libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

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
CONFIGURE_ARGS+=--without-x --mandir=${STAGEDIR}${PREFIX}/man --with-magickpackage=GraphicsMagick
CONFIGURE_ARGS+=--without-v4l
.for p in tiff jpeg zip png
CONFIGURE_ARGS+=--with-$p-includes=${LOCALBASE}/include
CONFIGURE_ARGS+=--with-$p-libraries=${LOCALBASE}/lib
.endfor

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
LIB_DEPENDS+=	liboil-0.3.so:${PORTSDIR}/devel/liboil
.else
CONFIGURE_ARGS+=	--without-liboil
.endif

post-patch:
	@${REINPLACE_CMD} -e '/VIPS_CXX_LIBS="-lstdc++"/ d' \
		${WRKSRC}/configure.in ${WRKSRC}/configure

.include <bsd.port.post.mk>
