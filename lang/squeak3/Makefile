# New ports collection makefile for:   	squeak
# Version required:    			2.3
# Date created:        			4 March 1999
# Whom:                			jesse@cs.uni-magdeburg.de
#
# $FreeBSD$
#

DISTNAME=	2.4
PKGNAME=	squeak-2.4
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.uni-magdeburg.de/pub/Smalltalk/Smalltalk/Squeak/unix/ \
		ftp://ftp.cs.uni-magdeburg.de/pub/Smalltalk/Smalltalk/Squeak/unix/image/ \
		http://www.nectar.com/distfiles/squeak/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} image/${SQUEAK_SRC}

MAINTAINER=	jesse@cs.uni-magdeburg.de

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
	${INSTALL_PROGRAM} SqueakVM-2.4-${VMBUILD} ${PREFIX}/bin/SqueakVM)
	${MKDIR} ${PREFIX}/share/squeak
.for f in Squeak2.4.changes Squeak2.4.image
	(cd ${WRKSRC}/image && ${INSTALL_DATA} $f ${PREFIX}/share/squeak/$f)
.endfor
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/image/${SQUEAK_SRC} \
		${PREFIX}/share/squeak/${SQUEAK_SRC}

.include <bsd.port.mk>
