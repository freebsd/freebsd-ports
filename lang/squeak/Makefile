# Created by: Roland Jesse <roland.jesse@gmx.net>

PORTNAME=	squeak
PORTVERSION=	4.10.2
PORTREVISION=	10
CATEGORIES=	lang
MASTER_SITES=	http://www.squeakvm.org/unix/release/:vmsrc \
		http://ftp.squeak.org/${IMAGE_VERSION}/:src \
		ftp://squeak.org/${IMAGE_VERSION}/:sqsrc \
		http://squeak.610t.org/patches/:mainsrc
DISTFILES=	Squeak-${VM_VERSION}-src${EXTRACT_SUFX}:vmsrc \
		Squeak${IMAGE_FULL_VERSION}.zip:src \
		${SQUEAK_SRC}.zip:sqsrc
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	Squeak-${VM_VERSION}-src${EXTRACT_SUFX}

MAINTAINER=	takeshi.mutoh@gmail.com
COMMENT=	Full Smalltalk 80 with portability to Unix, Mac, and Windows

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=		aarch64 amd64 i386 powerpc powerpc64 powerpc64le powerpcspe

BUILD_DEPENDS=	cmake:devel/cmake \
		v4l_compat>=1.0.20120501:multimedia/v4l_compat
LIB_DEPENDS=	libaudio.so:audio/nas \
		libdbus-1.so:devel/dbus \
		libffi.so:devel/libffi \
		libfreetype.so:print/freetype2 \
		libasound.so:audio/alsa-lib \
		libpulse-simple.so:audio/pulseaudio \
		libv4l2.so:multimedia/libv4l

USES=		gl gnome iconv pkgconfig xorg
USE_GL=		gl
USE_GNOME=	cairo pango
USE_XORG=	ice sm x11 xext xrender 

VM_VERSION=	${PORTVERSION}.${SVN_VERSION}
SVN_VERSION=	2614
IMAGE_VERSION=	4.6
IMAGE_SVN_VERSION=	15102
IMAGE_FULL_VERSION=	${IMAGE_VERSION}-${IMAGE_SVN_VERSION}
SQUEAK_SRC=	SqueakV46.sources
SQUEAK_LIB_DIR=	${PORTVERSION}-${SVN_VERSION}

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	unix/cmake/configure
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_OUTSOURCE=	yes

SUB_FILES=	pkg-message
SUB_LIST=	SQUEAK_LIB_DIR=${SQUEAK_LIB_DIR} \
		IMAGE_FULL_VERSION=${IMAGE_FULL_VERSION}

WRKSRC=		${WRKDIR}/Squeak-${VM_VERSION}-src

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
