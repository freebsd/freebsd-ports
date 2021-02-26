# Created by: Corey Smith <corsmith@gmail.com>
# $FreeBSD$
#
# To update the port:
# The stable libyuv version follows the chromium browser:
# https://chromereleases.googleblog.com/search/label/Desktop%20Update
# search for "The stable channel has been updated to" XX.X.XXXX.XXX
#  -> https://github.com/chromium/chromium/blob/87.0.4280.88/DEPS
#     -> 'src/third_party/libyuv': '6afd9becdf58822b1da6770598d8597c583ccfad'
# https://chromium.googlesource.com/libyuv/libyuv/+/6afd9becdf58822b1da6770598d8597c583ccfad/include/libyuv/version.h
#  -> #define LIBYUV_VERSION 1741

PORTNAME=	libyuv
DISTVERSION=	0.0.1767
CATEGORIES=	graphics
MASTER_SITES=	LOCAL/mikael/libyuv/:libyuv \
		LOCAL/tcberner/libyuv/:libyuv
DISTFILES=	libyuv-${LIBYUV_HASH}.tar.gz:libyuv

MAINTAINER=	corsmith@gmail.com
COMMENT=	Library for freeswitch yuv graphics manipulation

LICENSE=	BSD3CLAUSE

USES=		cmake pkgconfig
USE_LDCONFIG=	yes
SUB_FILES=	libyuv.pc
SUB_LIST=	DISTVERSION=${DISTVERSION}

LIBYUV_HASH=	f014dbd87ab06258569ad10a4cb6f84a8a7f7dd2

# sha256 changes everytime you download the archive, need to host it on freefall
# To download the distfile: as mikael: make MAINTAINER_MODE=yes fetch
.if defined(MAINTAINER_MODE)
do-fetch:
	${FETCH_CMD} -o ${DISTDIR}/libyuv-${LIBYUV_HASH}.tar.gz \
		https://chromium.googlesource.com/libyuv/libyuv.git/+archive/${LIBYUV_HASH}.tar.gz

. if ${USER} == ${MAINTAINER:C/@.*//}
	scp ${DISTDIR}/libyuv-${LIBYUV_HASH} freefall.freebsd.org:public_distfiles/libyuv
. endif
.endif # defined(MAINTAINER_MODE)

do-extract:
	${MKDIR} ${WRKSRC}
	${TAR} -xf ${DISTDIR}/libyuv-${LIBYUV_HASH}.tar.gz  -C ${WRKSRC}

post-install:
	(cd ${WRKDIR} && ${INSTALL_DATA} libyuv.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig)

.include <bsd.port.mk>
