# New ports collection makefile for:   	squeak
# Version required:    			2.2
# Date created:        			12/01/1998
# Whom:                			nectar@FreeBSD.ORG
#
# $Id: Makefile,v 1.5 1998/12/03 04:35:44 nectar Exp $
#

DISTNAME=	2.2
PKGNAME=	squeak-2.2
CATEGORIES=	lang
MASTER_SITES=	http://www.nectar.com/distfiles/squeak/ \
		ftp://alix.inria.fr/pub/squeak/unix/ \
		ftp://st.cs.uiuc.edu/pub/Smalltalk/Squeak/unix/ \
		http://st-www.cs.uiuc.edu/ftp/Smalltalk/Squeak/ \
		ftp://uiarchive.cso.uiuc.edu/pub/lang/smalltalk/smalltalk/Squeak/ \
		http://wuarchive.wustl.edu/languages/smalltalk/smalltalk/Squeak/ \
		ftp://ftp.cs.uni-magdeburg.de/pub/Smalltalk/Smalltalk/Squeak/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} image/${SQUEAK_SRC}

MAINTAINER=	nectar@FreeBSD.ORG

ALLFILES=	${DISTNAME}${EXTRACT_SUFX} ${SQUEAK_SRC}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_XLIB=	yes
DIST_SUBDIR=	squeak
SQUEAK_SRC=	SqueakV2.sources
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
	${INSTALL_PROGRAM} SqueakVM-2.2-${VMBUILD} ${PREFIX}/bin/SqueakVM)
	${MKDIR} ${PREFIX}/share/squeak
.for f in Squeak2.2.changes Squeak2.2.image
	(cd ${WRKSRC}/image && ${INSTALL_DATA} $f ${PREFIX}/share/squeak/$f)
.endfor
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${SQUEAK_SRC} \
		${PREFIX}/share/squeak/${SQUEAK_SRC}

.include <bsd.port.mk>
