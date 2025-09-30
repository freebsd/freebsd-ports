PORTNAME=	virtual_oss_bluetooth
DISTVERSION=	${OSVERSION}
CATEGORIES=	audio
DISTFILES=

MAINTAINER=	christos@FreeBSD.org
COMMENT=	Bluetooth backend for virtual_oss
WWW=		https://freebsd.org

LICENSE=	BSD2CLAUSE

USES=		pathfix uidfix
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	LIBAV
OPTIONS_DEFAULT=

LIBAV_DESC=		Build with libav support for AAC audio
LIBAV_LIB_DEPENDS=	libavdevice.so:multimedia/gstreamer1-libav \
			libavutil.so:multimedia/gstreamer1-libav \
			libavcodec.so:multimedia/gstreamer1-libav \
			libavformat.so:multimedia/gstreamer1-libav
LIBAV_MAKE_ENV=		HAVE_LIBAV=YES

MAKE_ENV=	LIBDIR=${PREFIX}/lib \
		MAKEOBJDIRPREFIX=${WRKDIR}

WRKSRC=		${SRC_BASE}/lib/virtual_oss/bt

PLIST_FILES=	lib/virtual_oss/voss_bt.so

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/virtual_oss

.include <bsd.port.pre.mk>

.if !exists(${WRKSRC})
IGNORE=		requires FreeBSD source files in ${SRC_BASE}
.endif

.include <bsd.port.post.mk>
