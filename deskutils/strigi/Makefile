# Created by: Tilman Keskinoz <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	strigi
PORTVERSION=	0.7.8
CATEGORIES=	deskutils
MASTER_SITES=	http://www.vandenoever.info/software/strigi/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Desktop searching program

LIB_DEPENDS=	avcodec${FFMPEG_SUFFIX}:${PORTSDIR}/multimedia/ffmpeg${FFMPEG_SUFFIX} \
		clucene-core:${PORTSDIR}/textproc/clucene \
		dbus-1:${PORTSDIR}/devel/dbus \
		exiv2.12:${PORTSDIR}/graphics/exiv2 \
		boost_thread:${PORTSDIR}/devel/boost-libs

USE_QT4=	corelib gui dbus moc_build uic_build qmake_build rcc_build
USE_BZIP2=	yes
USE_GNOME=	libxml2
USE_PKGCONFIG=	build
USE_FAM=	yes
USE_LDCONFIG=	yes
USES=		cmake
MAKE_JOBS_UNSAFE=	yes

# supported versions: ffmpeg, ffmpeg1, ffmpeg-devel
FFMPEG_SUFFIX?=	#

post-patch:
	${MKDIR} ${WRKSRC}
	${REINPLACE_CMD} -e \
		's,$${LIB_DESTINATION}/pkgconfig,libdata/pkgconfig,' \
		${WRKSRC}/libstreamanalyzer/CMakeLists.txt \
		${WRKSRC}/libstreams/CMakeLists.txt

.include <bsd.port.mk>
