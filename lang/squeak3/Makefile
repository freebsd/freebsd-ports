# New ports collection makefile for:   	squeak
# Date created:        			12 October 2001
# Whom:                			roland.jesse@gmx.net
#
# $FreeBSD$
#

PORTNAME=	squeak
PORTVERSION=	3.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.uni-magdeburg.de/pub/Smalltalk/Smalltalk/Squeak/3.2/unix-linux/ \
		ftp://ftp.cs.uni-magdeburg.de/pub/Smalltalk/Smalltalk/Squeak/3.2/ \
		ftp://st.cs.uiuc.edu/Smalltalk/Squeak/3.2/unix-linux/
DISTNAME=	Squeak-${SQUEAK_VERSION}.src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${SQUEAK_SRC} ${SQUEAK_IMAGE_SRC}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	roland.jesse@gmx.net

# Don't set USE_ZIP as this breaks EXTRACT_CMD, EXTRACT_SUFX, and what not.
BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

SQUEAK_VERSION=	3.2-4
SQUEAK_PATCHNR=	4956
SQUEAK_SRC=	SqueakV3.sources.gz
SQUEAK_IMAGE_SRC=	Squeak3.2-4956.zip
SQUEAK_IMAGE=	Squeak3.2-${SQUEAK_PATCHNR}.image \
		Squeak3.2-${SQUEAK_PATCHNR}.changes

WRKSRC=		${WRKDIR}/Squeak-${SQUEAK_VERSION}
MAN1=		inisqueak.1 squeak.1
USE_XLIB=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	${PREFIX}/share/squeak/${SQUEAK_VERSION}
CONFIGURE_WRKSRC=	${WRKSRC}/build
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}
CONFIGURE_SCRIPT=	../platforms/unix/config/configure
CONFIGURE_ARGS+=	--libdir=${PREFIX}/share
# don't pass "-s" to install to avoid trying to strip a shell script
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}"
BUILD_WRKSRC=	${WRKSRC}/build
DIST_SUBDIR=	squeak

MAKEFILE=	Makefile
.ifdef (CC)
MAKE_ARGS+=	CC=${CC}
.endif
.ifdef (CFLAGS)
MAKE_ARGS+=	CCFLAGS="${CFLAGS}"
.endif

pre-configure:
	@${MKDIR} ${BUILD_WRKSRC}

post-install:
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${SQUEAK_SRC} ${PREFIX}/share/squeak/)
	(cd ${PREFIX}/share/squeak && ${EXTRACT_CMD} -d ${SQUEAK_SRC})
	(cd ${PREFIX}/share/squeak && unzip -x ${DISTDIR}/${DIST_SUBDIR}/${SQUEAK_IMAGE_SRC})
.for file in ${SQUEAK_IMAGE}
	(cd ${PREFIX}/share/squeak && ${GZIP_CMD} ${file})
.endfor
	strip ${PREFIX}/share/squeak/${SQUEAK_VERSION}/squeak
# install inisqueak and change the build in version number on the fly
	${SED} -e 's|VERSION=3.2gamma-4881|VERSION=3.2-4956|' ${WRKSRC}/build/inisqueak > ${PREFIX}/bin/inisqueak
	(cd ${PREFIX}/bin && ${CHMOD} 755 inisqueak)
	@${ECHO} "--------------- Please note: ---------------"
	@${ECHO} "Make sure you have ${PREFIX}/bin in your PATH"
	@${ECHO} "and ${PREFIX}/lib in your LD_LIBRARY_PATH."
	@${ECHO} ""
	@${ECHO} "In order to be able to make use of squeak you need"
	@${ECHO} "to have an image and a changes file in your working"
	@${ECHO} "directory as well as access to a source file."
	@${ECHO} "Please see the inisqueak(1) manpage for details."
	@${ECHO} "--------------- Thanks for listening. ---------------"

.include <bsd.port.mk>
