# New ports collection makefile for:   	squeak
# Version required:    			2.3
# Date created:        			4 March 1999
# Whom:                			jesse@cs.uni-magdeburg.de
#
# $Id$
#

DISTNAME=	2.3
PKGNAME=	squeak-2.3
CATEGORIES=	lang
MASTER_SITES=	ftp://alix.inria.fr/pub/squeak/unix/ \
		ftp://alix.inria.fr/pub/squeak/unix/2.3/ \
		ftp://ftp.cs.uni-magdeburg.de/pub/Smalltalk/Smalltalk/Squeak/ \
		ftp://ftp.cs.uni-magdeburg.de/pub/Smalltalk/Smalltalk/Squeak/2.3/ \
		http://www.nectar.com/distfiles/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} image/${SQUEAK_SRC}

MAINTAINER=	jesse@cs.uni-magdeburg.de

ALLFILES=	${DISTNAME}${EXTRACT_SUFX} ${SQUEAK_SRC}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_XLIB=	yes
USE_GMAKE=	yes
DIST_SUBDIR=	squeak
SQUEAK_SRC=	SqueakV2.sources
MAKEFILE=	GNUmakefile
VMBUILD=	freebsd
MAKE_ARGS=	VMBUILD=${VMBUILD}
PORTMAKE=	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS}

do-build:
	@(cd ${WRKSRC} && ${PORTMAKE} mkdir)
	@(cd ${WRKSRC}/${VMBUILD} && ${PORTMAKE} interp)

do-install:
	@(cd ${WRKSRC}/${VMBUILD} && \
	${INSTALL_PROGRAM} SqueakVM-2.3-${VMBUILD} ${PREFIX}/bin/SqueakVM)
	${MKDIR} ${PREFIX}/share/squeak
.for f in Squeak2.3.changes Squeak2.3.image
	(cd ${WRKSRC}/image && ${INSTALL_DATA} $f ${PREFIX}/share/squeak/$f)
.endfor
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${SQUEAK_SRC} \
		${PREFIX}/share/squeak/${SQUEAK_SRC}

.include <bsd.port.mk>
