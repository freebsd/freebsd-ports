# Created by: Roland Jesse <roland.jesse@gmx.net>
# $FreeBSD$

PORTNAME=	squeak
PORTVERSION=	4.10.2
CATEGORIES=	lang
MASTER_SITES=	http://www.squeakvm.org/unix/release/:vmsrc \
		http://ftp.squeak.org/${IMAGE_VERSION}/:src \
		ftp://squeak.org/4.1/:sqsrc \
		http://squeak.610t.org/patches/:mainsrc
DISTFILES=	Squeak-${VM_VERSION}-src${EXTRACT_SUFX}:vmsrc \
		Squeak${IMAGE_VERSION}.zip:src \
		${SQUEAK_SRC}.gz:sqsrc
EXTRACT_ONLY=	Squeak-${VM_VERSION}-src${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full Smalltalk 80 with portability to Unix, Mac, and Windows

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake \
		v4l_compat>=1.0.20120501:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	libaudio.so:${PORTSDIR}/audio/nas \
		libffi.so:${PORTSDIR}/devel/libffi \
		libasound.so:${PORTSDIR}/audio/alsa-lib \
		libpulse-simple.so:${PORTSDIR}/audio/pulseaudio \
		libv4l2.so:${PORTSDIR}/multimedia/libv4l

ONLY_FOR_ARCHS=	i386 amd64 powerpc

USES=		pkgconfig
USE_GL=		gl
HAS_CONFIGURE=	yes
USE_GSTREAMER=	yes

VM_VERSION=	${PORTVERSION}.${SVN_VERSION}
SVN_VERSION=	2614
IMAGE_VERSION=	4.3
SQUEAK_SRC=	SqueakV41.sources
SQUEAK_LIB_DIR=	${PORTVERSION}-${SVN_VERSION}

WRKSRC=			${WRKDIR}/Squeak-${VM_VERSION}-src
CONFIGURE_WRKSRC=	${WRKSRC}/build
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=		${CONFIGURE_WRKSRC}
CONFIGURE_SCRIPT=	../unix/cmake/configure
CONFIGURE_ARGS=		--prefix=${PREFIX}
CMAKE_SOURCE_PATH=	../unix

SUB_FILES=	pkg-message
SUB_LIST=	SQUEAK_LIB_DIR=${SQUEAK_LIB_DIR}
PLIST_SUB=	SQUEAK_LIB_DIR=${SQUEAK_LIB_DIR}

IMAGES=		Squeak${IMAGE_VERSION}/Squeak${IMAGE_VERSION}.image \
		Squeak${IMAGE_VERSION}/Squeak${IMAGE_VERSION}.changes

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} > 900007
	@${REINPLACE_CMD} -e 's,<utmp\.h>,<utmpx.h>,' \
		${WRKSRC}/unix/plugins/PseudoTTYPlugin/openpty.h
.endif
	@${REINPLACE_CMD} -e 's,return;,return 0;,' \
		${WRKSRC}/Cross/plugins/Mpeg3Plugin/libmpeg/video/idct.c \
		${WRKSRC}/Cross/plugins/Mpeg3Plugin/libmpeg/audio/layer3.c
	@${REINPLACE_CMD} -e 's,return;,return 1;,' \
		${WRKSRC}/Cross/plugins/Mpeg3Plugin/libmpeg/video/getpicture.c

pre-configure:
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-install:
	${GUNZIP_CMD} -c ${_DISTDIR}/${SQUEAK_SRC}.gz > \
		${STAGEDIR}${PREFIX}/lib/squeak/${SQUEAK_LIB_DIR}/${SQUEAK_SRC}
	${UNZIP_NATIVE_CMD} -u ${_DISTDIR}/Squeak${IMAGE_VERSION}.zip \
		-d ${WRKDIR}
	${INSTALL_DATA} ${IMAGES:S,^,${WRKDIR}/,} \
		${STAGEDIR}${PREFIX}/lib/squeak

.include <bsd.port.post.mk>
