# New ports collection makefile for:   	squeak
# Date created:        			12 October 2001
# Whom:                			jesse@cs.uni-magdeburg.de
#
# $FreeBSD$
#

PORTNAME=	squeak
PORTVERSION=	3.0
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.uni-magdeburg.de/pub/Smalltalk/Smalltalk/Squeak/3.0/unix-linux/src/ \
		ftp://ftp.cs.uni-magdeburg.de/pub/Smalltalk/Smalltalk/Squeak/3.0/platform-independent/
DISTNAME=	Squeak-${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${SQUEAK_SRC} ${SQUEAK_IMAGE_SRC}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jesse@cs.uni-magdeburg.de

# Don't set USE_ZIP as this breaks EXTRACT_CMD, EXTRACT_SUFX, and what not.
BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

SQUEAK_SRC=	SqueakV3.sources.gz
SQUEAK_IMAGE_SRC=	Squeak3.0-3552.zip
SQUEAK_IMAGE=	Squeak3.0.image Squeak3.0.changes

WRKSRC=		${WRKDIR}/Squeak-3.0
USE_XLIB=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	${PREFIX}/share/squeak/3.0
CONFIGURE_WRKSRC=	${WRKSRC}/build
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}
CONFIGURE_SCRIPT=	../src/unix/configure
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
	(cd ${PREFIX}/share/squeak && ${CHMOD} 644 Squeak3.0.changes)
	strip ${PREFIX}/share/squeak/3.0/squeak
	@${ECHO} "--------------- Please note: ---------------"
	@${ECHO} "Make sure you have ${PREFIX}/bin in your PATH"
	@${ECHO} "and ${PREFIX}/lib in your LD_LIBRARY_PATH."
	@${ECHO} ""
	@${ECHO} "In order to be able to make use of squeak you need"
	@${ECHO} "to have an image and a changes file in your working"
	@${ECHO} "directory as well as access to a source file."
	@${ECHO} "Execute the following:"
	@${ECHO} "cd <your_private_working_directory>"
	@${ECHO} "cp ${PREFIX}/share/squeak/Squeak3.0.image ."
	@${ECHO} "cp ${PREFIX}/share/squeak/Squeak3.0.changes ."
	@${ECHO} "ln -s ${PREFIX}/share/squeak/SqueakV3.sources ."
	@${ECHO} ""
	@${ECHO} "To finally start up the system type:"
	@${ECHO} "squeak Squeak3.0.image"
	@${ECHO} "--------------- Thanks for listening. ---------------"

.include <bsd.port.mk>
