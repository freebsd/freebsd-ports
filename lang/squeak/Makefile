# Created by: Roland Jesse <roland.jesse@gmx.net>
# $FreeBSD$

PORTNAME=	squeak
PORTVERSION=	4.10.2
PORTREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	http://www.squeakvm.org/unix/release/:vmsrc \
		http://ftp.squeak.org/${IMAGE_VERSION}/:src \
		ftp://squeak.org/${IMAGE_VERSION}/:sqsrc \
		http://squeak.610t.org/patches/:mainsrc
DISTFILES=	Squeak-${VM_VERSION}-src${EXTRACT_SUFX}:vmsrc \
		Squeak${IMAGE_FULL_VERSION}.zip:src \
		${SQUEAK_SRC}.zip:sqsrc
EXTRACT_ONLY=	Squeak-${VM_VERSION}-src${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full Smalltalk 80 with portability to Unix, Mac, and Windows

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi

BUILD_DEPENDS=	cmake:devel/cmake \
		v4l_compat>=1.0.20120501:multimedia/v4l_compat
LIB_DEPENDS=	libaudio.so:audio/nas \
		libffi.so:devel/libffi \
		libasound.so:audio/alsa-lib \
		libpulse-simple.so:audio/pulseaudio \
		libv4l2.so:multimedia/libv4l

ONLY_FOR_ARCHS=	i386 amd64 powerpc

USES=		pkgconfig
USE_GNOME=	cairo pango
USE_GL=		gl
HAS_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
USE_GSTREAMER=	yes

VM_VERSION=	${PORTVERSION}.${SVN_VERSION}
SVN_VERSION=	2614
IMAGE_VERSION=	4.6
IMAGE_SVN_VERSION=	15102
IMAGE_FULL_VERSION=	${IMAGE_VERSION}-${IMAGE_SVN_VERSION}
SQUEAK_SRC=	SqueakV46.sources
SQUEAK_LIB_DIR=	${PORTVERSION}-${SVN_VERSION}

WRKSRC=			${WRKDIR}/Squeak-${VM_VERSION}-src
CONFIGURE_SCRIPT=	unix/cmake/configure
CONFIGURE_ARGS=		--prefix=${PREFIX}
CMAKE_SOURCE_PATH=	unix

SUB_FILES=	pkg-message
SUB_LIST=	SQUEAK_LIB_DIR=${SQUEAK_LIB_DIR} \
		IMAGE_FULL_VERSION=${IMAGE_FULL_VERSION}
PLIST_SUB=	SQUEAK_LIB_DIR=${SQUEAK_LIB_DIR} \
		IMAGE_FULL_VERSION=${IMAGE_FULL_VERSION}

IMAGES=		Squeak${IMAGE_FULL_VERSION}.image \
		Squeak${IMAGE_FULL_VERSION}.changes \
		${SQUEAK_SRC}

post-patch:
	@${REINPLACE_CMD} -e 's,<utmp\.h>,<utmpx.h>,' \
		${WRKSRC}/unix/plugins/PseudoTTYPlugin/openpty.h
	@${REINPLACE_CMD} -e 's,return;,return 0;,' \
		${WRKSRC}/Cross/plugins/Mpeg3Plugin/libmpeg/video/idct.c \
		${WRKSRC}/Cross/plugins/Mpeg3Plugin/libmpeg/audio/layer3.c
	@${REINPLACE_CMD} -e 's,return;,return 1;,' \
		${WRKSRC}/Cross/plugins/Mpeg3Plugin/libmpeg/video/getpicture.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/squeak/${SQUEAK_LIB_DIR}/so.* \
		${STAGEDIR}${PREFIX}/lib/squeak/${SQUEAK_LIB_DIR}/squeakvm \
		${STAGEDIR}${PREFIX}/lib/squeak/${SQUEAK_LIB_DIR}/ckformat
	${UNZIP_NATIVE_CMD} -u ${_DISTDIR}/${SQUEAK_SRC}.zip -d ${WRKDIR}
	${UNZIP_NATIVE_CMD} -u ${_DISTDIR}/Squeak${IMAGE_FULL_VERSION}.zip \
		-d ${WRKDIR}
	${INSTALL_DATA} ${IMAGES:S,^,${WRKDIR}/,} \
		${STAGEDIR}${PREFIX}/lib/squeak

.include <bsd.port.mk>
