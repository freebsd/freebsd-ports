# New ports collection makefile for:   	squeak1
# Version required:    			1.31
# Date created:        			20 December 1998
# Whom:                			jesse@cs.uni-magdeburg.de
#
# $Id: Makefile,v 1.5 1998/12/23 04:32:27 steve Exp $
#

DISTNAME=	1.31
PKGNAME=	squeak-1.31
CATEGORIES=	lang
MASTER_SITES=	http://www.apfel.de/~jesse/squeak/ \
		ftp://alix.inria.fr/pub/squeak/unix/ \
		ftp://st.cs.uiuc.edu/pub/Smalltalk/Squeak/unix/ \
		ftp://ftp.cs.uni-magdeburg.de/pub/Smalltalk/Smalltalk/Squeak/ \
		ftp://ftp.cs.uni-magdeburg.de/pub/Smalltalk/Smalltalk/Squeak/unix/ \
		http://st-www.cs.uiuc.edu/ftp/Smalltalk/Squeak/ \
		ftp://uiarchive.cso.uiuc.edu/pub/lang/smalltalk/smalltalk/Squeak/ \
		http://wuarchive.wustl.edu/languages/smalltalk/smalltalk/Squeak/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} image/${SQUEAK_SRC}

MAINTAINER=	jesse@cs.uni-magdeburg.de

ALLFILES=	${DISTNAME}${EXTRACT_SUFX} ${SQUEAK_SRC}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_XLIB=	yes
DIST_SUBDIR=	squeak
SQUEAK_SRC=	SqueakV1.sources
USE_GMAKE=	yes
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
	${INSTALL_PROGRAM} SqueakVM-1.31-${VMBUILD} ${PREFIX}/bin/SqueakVM)
	${MKDIR} ${PREFIX}/share/squeak
.for f in Squeak1.31.changes Squeak1.31.image
	(cd ${WRKSRC}/image && ${INSTALL_DATA} $f ${PREFIX}/share/squeak/$f)
.endfor
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${SQUEAK_SRC} \
		${PREFIX}/share/squeak/${SQUEAK_SRC}

.include <bsd.port.mk>
