# New ports collection makefile for:	quackle
# Date created:			15 Feb 2008
# Whom:				shoemaker@bluebottle.com (Jonathan Shoemaker)
#
# $FreeBSD$
#

PORTNAME=	quackle
PORTVERSION=	0.97
PORTREVISION=	2
DISTVERSIONSUFFIX=	-source
CATEGORIES=	games
MASTER_SITES=	http://people.csail.mit.edu/jasonkb/quackle/downloads/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	A scrabble-like word game utilizing qt4

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/quacker

USE_QT4=	corelib gui moc_build qmake_build
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES="Quackle" "${COMMENT}" "" "quackle" "Game;BoardGame;" "true"

post-extract:
	@${FIND} ${WRKSRC} \( -name "*.[ao]" -or -name "moc_*" \) -delete

post-patch:
	@${REINPLACE_CMD} -e \
		'/debug/s|^CONFIG|#CONFIG| ; \
		 /release/s|^#CONFIG|CONFIG|' ${BUILD_WRKSRC}/quacker.pro
	@${REINPLACE_CMD} -e \
		'/QFile::exists/s|("data")|("${DATADIR}")| ; \
		 /setDataDirectory/s|("data")|("${DATADIR}")|' ${BUILD_WRKSRC}/settings.cpp

do-configure:
.for dir in . quackleio quacker
	@(cd ${WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS})
.endfor

pre-build:
.for dir in . quackleio
	@(cd ${WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.endfor

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/quacker ${PREFIX}/bin/quackle
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${DATADIR})

.include <bsd.port.mk>
