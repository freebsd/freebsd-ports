# $FreeBSD$

PORTNAME=		libheif
DISTVERSIONPREFIX=	v
DISTVERSION=		1.6.2
PORTREVISION=		2
CATEGORIES=		graphics

MAINTAINER=		freebsd@sebastiansteinmetz.ch
COMMENT=		Libheif is an ISO/IEC 23008-12:2017 HEIF file format de- and encoder

# N.B., subsequent revisions in Git relicense examples from GPL3+ to MIT.
LICENSE=		LGPL3+
LICENSE_FILE_LGPL3+ =	${WRKSRC}/COPYING

USES=			autoreconf compiler:c++11-lang libtool localbase pkgconfig \
			shebangfix
USE_GITHUB=		yes
GH_ACCOUNT=		strukturag
GH_PROJECT=		libheif
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--disable-go
USE_LDCONFIG=		yes
SHEBANG_GLOB=		*.sh
INSTALL_TARGET=		install-strip

OPTIONS_DEFINE=	EXAMPLES JPEG LIBDE265 PNG THREADS X265
OPTIONS_DEFAULT=EXAMPLES JPEG LIBDE265 PNG THREADS X265
OPTIONS_SUB=	yes

EXAMPLES_DESC=	Install example programs (heif-convert, heif-enc, heif-info, heif-thumbnailer)
LIBDE265_DESC=	Use libde265 (support for HEVC decoding)
X265_DESC=	Use x265 (support for HEVC encoding)

JPEG_USES=		jpeg
LIBDE265_LIB_DEPENDS=	libde265.so:multimedia/libde265
PNG_LIB_DEPENDS=	libpng.so:graphics/png
THREADS_CONFIGURE_OFF=	--disable-multithreading
X265_LIB_DEPENDS=	libx265.so:multimedia/x265

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
LICENSE+=		GPLv3+
LICENSE_COMB=		multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/examples/COPYING
USES+=			shared-mime-info
.endif

post-patch-JPEG-off:
	@${REINPLACE_CMD} -e '/AC_CHECK_/ s|jpeg|ignore&|g' ${WRKSRC}/configure.ac

post-patch-LIBDE265-off:
	@${REINPLACE_CMD} -e '/PKG_CHECK_MODULES/ s|libde265|ignore&|g' ${WRKSRC}/configure.ac

post-patch-PNG-off:
	@${REINPLACE_CMD} -e '/PKG_CHECK_MODULES/ s|png|ignore&|g' ${WRKSRC}/configure.ac

post-patch-X265-off:
	@${REINPLACE_CMD} -e '/PKG_CHECK_MODULES/ s|x265|ignore&|g' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
