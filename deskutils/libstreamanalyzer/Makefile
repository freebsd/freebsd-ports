# $FreeBSD$

PORTNAME=	libstreamanalyzer
PORTVERSION=	${STRIGI_VERSION}
PORTREVISION=	7
CATEGORIES=	deskutils
MASTER_SITES=	${STRIGI_MASTER_SITES}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Strigi desktop search: streamanalyzer library

LIB_DEPENDS=	libavcodec${FFMPEG_SUFFIX}.so:multimedia/ffmpeg${FFMPEG_SUFFIX} \
		libclucene-core.so:textproc/clucene \
		libexiv2.so:graphics/exiv2 \
		libstreams.so:deskutils/libstreams

USES=		pkgconfig iconv
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

# supported versions: ffmpeg, ffmpeg1, ffmpeg-devel
# corresponding FFMPEG_SUFFIX: '', '1', '-devel'
FFMPEG_SUFFIX?=
CMAKE_ARGS+=	-DFFMPEG_SUFFIX:STRING="${FFMPEG_SUFFIX}"

.if !empty(FFMPEG_SUFFIX)
# Reorder include directories to allow build with multiple ffmpeg installed.
# This patch must NOT be used, if ffmpeg headers are installed
# directly to ${LOCALBASE}/include
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-libstreamanalyzer__plugins__endplugins__CMakeLists.txt
.endif

post-patch:
	${REINPLACE_CMD} -e \
		's,$${LIB_DESTINATION}/pkgconfig,libdata/pkgconfig,' \
		${WRKSRC}/libstreamanalyzer/CMakeLists.txt

.include <${.CURDIR}/../strigi/Makefile.common>
.include <bsd.port.mk>
