# New ports collection makefile for:   	squeak
# Date created:        			4 March 1999
# Whom:                			jesse@cs.uni-magdeburg.de
#
# $FreeBSD$
#

PORTNAME=	squeak
PORTVERSION=	2.7
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/SOR/users/piumarta/squeak/ \
		ftp://ftp.cs.uni-magdeburg.de/pub/Smalltalk/free/squeak/unix/
DISTNAME=	Squeak-${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${SQUEAK_SRC}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jesse@cs.uni-magdeburg.de
COMMENT=	Full Smalltalk 80 with portability to UNIX, Mac, and Windows

NO_WRKSUBDIR=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
DIST_SUBDIR=	squeak
SQUEAK_SRC=	SqueakV2.sources.gz Squeak-2.7.image.gz Squeak-2.7.changes.gz
SQUEAK_LIB=	Profiler.so SoundCodecPrims.so Squeak3D.so System.so

MAKEFILE=	Makefile
.ifdef (CC)
MAKE_ARGS+=	CC=${CC}
.endif
.ifdef (CFLAGS)
MAKE_ARGS+=	CCFLAGS="${CFLAGS}"
.endif

do-install:
	@(cd ${WRKSRC}/freebsd && \
	${INSTALL_PROGRAM} squeak ${PREFIX}/bin/squeak)
	${MKDIR} ${PREFIX}/share/squeak
.for l in ${SQUEAK_LIB}
	(cd ${WRKSRC}/freebsd && ${INSTALL_DATA} $l ${PREFIX}/lib/$l)
.endfor
.for f in ${SQUEAK_SRC}
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} $f ${PREFIX}/share/squeak/$f)
	(cd ${PREFIX}/share/squeak && ${EXTRACT_CMD} -d $f)
.endfor
	(cd ${PREFIX}/share/squeak && ${CHMOD} 644 Squeak-2.7.changes)

post-install:
	@${ECHO} "Make sure you have ${PREFIX}/bin in your PATH"
	@${ECHO} "and ${PREFIX}/lib in your LD_LIBRARY_PATH."
	@${ECHO} ""
	@${ECHO} "In order to be able to make use of squeak you need"
	@${ECHO} "to have an image and a changes file in your working"
	@${ECHO} "directory as well as access to a source file."
	@${ECHO} "Execute the following:"
	@${ECHO} "cd <your_private_working_directory>"
	@${ECHO} "cp ${PREFIX}/share/squeak/Squeak-2.7.image ."
	@${ECHO} "cp ${PREFIX}/share/squeak/Squeak-2.7.changes ."
	@${ECHO} "ln -s ${PREFIX}/share/squeak/SqueakV2.sources ."
	@${ECHO} ""
	@${ECHO} "To finally start up the system type:"
	@${ECHO} "squeak Squeak-2.7.image"

.include <bsd.port.mk>
