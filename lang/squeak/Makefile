# Created by: roland.jesse@gmx.net
# $FreeBSD$

PORTNAME=		squeak
PORTVERSION=		4.10.2
CATEGORIES=		lang
##################################################
MASTER_SITES=		http://www.squeakvm.org/unix/release/:vmsrc \
			http://ftp.squeak.org/${IMAGEVERSION}/:src \
			ftp://squeak.org/4.1/:sqsrc \
			http://squeak.610t.org/patches/:mainsrc
DISTFILES=		Squeak-${VM_VERSION}-src${EXTRACT_SUFX}:vmsrc \
			Squeak${IMAGEVERSION}.zip:src \
			${SQUEAK_SRC}.gz:sqsrc
EXTRACT_ONLY=		Squeak-${VM_VERSION}-src${EXTRACT_SUFX}

##################################################
MAINTAINER=		mutoh@openedu.org
COMMENT=		Full Smalltalk 80 with portability to UNIX, Mac, and Windows

LICENSE=		APACHE20 MIT
LICENSE_COMB=		multi

# Don't set USE_ZIP as this breaks EXTRACT_CMD.
BUILD_DEPENDS=		${UNZIP_CMD}:${PORTSDIR}/archivers/unzip \
			cmake:${PORTSDIR}/devel/cmake \
			v4l_compat>=1.0.20120501:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=		audio:${PORTSDIR}/audio/nas \
			ffi:${PORTSDIR}/devel/libffi \
			asound:${PORTSDIR}/audio/alsa-lib \
			pulse-simple:${PORTSDIR}/audio/pulseaudio \
			gstreamer:${PORTSDIR}/multimedia/gstreamer \
			v4l2:${PORTSDIR}/multimedia/libv4l

##################################################
VM_VERSION=		${PORTVERSION}.${SVNVERSION}
SVNVERSION=		2614
IMAGEVERSION=		4.3
SQUEAK_SRC=		SqueakV41.sources
SQUEAK_LIB_DIR=		${PORTVERSION}-${SVNVERSION}
USES=			pkgconfig

NO_STAGE=	yes
.include <bsd.port.pre.mk>

##################################################
DIST_SUBDIR=		squeak
ONLY_FOR_ARCHS=		i386 amd64
MAN1=			squeak.1
USE_GCC=		4.2+
USE_GL=			gl
HAS_CONFIGURE=		yes

# Plugin image must be writable, because of it copy to user's ~/.npsqueak/ and
# be updated.
SHAREMODE=		644

# shared Libaries are to be installed in:
LDCONFIG_DIRS=		${PREFIX}/lib/squeak/${VM_VERSION}

IMAGES=		Squeak${IMAGEVERSION}/Squeak${IMAGEVERSION}.image \
		Squeak${IMAGEVERSION}/Squeak${IMAGEVERSION}.changes

##################################################
# Configure and Build
WRKSRC=			${WRKDIR}/Squeak-${VM_VERSION}-src
CONFIGURE_WRKSRC=	${WRKSRC}/build
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=		${CONFIGURE_WRKSRC}
CONFIGURE_SCRIPT=	../unix/cmake/configure
CONFIGURE_ARGS+=	--prefix=${PREFIX}

CMAKE_SOURCE_PATH=	../unix

SUB_FILES=		pkg-message
SUB_LIST=		SQUEAK_LIB_DIR=${SQUEAK_LIB_DIR}

PLIST_SUB=		SQUEAK_LIB_DIR=${SQUEAK_LIB_DIR}

##################################################
post-patch:

# Fix utmp.h
.if ${OSVERSION} > 900007
	@${REINPLACE_CMD} \
		-e "s,<utmp.h>,<utmpx.h>,g" \
		${WRKSRC}/unix/plugins/PseudoTTYPlugin/openpty.h
.endif

##################################################
pre-configure:
	@${MKDIR} ${CONFIGURE_WRKSRC}

##################################################
post-install:
	${GUNZIP_CMD} -c ${DISTDIR}/${DIST_SUBDIR}/${SQUEAK_SRC}.gz > ${WRKDIR}/${SQUEAK_SRC} && ${INSTALL_DATA} ${WRKDIR}/${SQUEAK_SRC} ${PREFIX}/lib/squeak/${SQUEAK_LIB_DIR}/
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${UNZIP_CMD} -u Squeak${IMAGEVERSION}.zip -d ${WRKDIR})
.for f in ${IMAGES}
	(cd ${WRKDIR} && ${INSTALL_DATA} ${f} ${PREFIX}/lib/squeak/)
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
