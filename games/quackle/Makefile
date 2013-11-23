# Created by: shoemaker@bluebottle.com (Jonathan Shoemaker)
# $FreeBSD$

PORTNAME=	quackle
PORTVERSION=	0.97
PORTREVISION=	2
DISTVERSIONSUFFIX=	-source
CATEGORIES=	games
MASTER_SITES=	http://people.csail.mit.edu/jasonkb/quackle/downloads/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Scrabble-like word game utilizing Qt4

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/quacker

USES=		gmake qmake
USE_GCC=	any
USE_QT4=	gui moc_build

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

post-configure:
.for dir in quackleio quacker
	@(cd ${WRKSRC}/${dir} && ${SETENV} ${QMAKE_ENV} ${QMAKE} ${QMAKE_ARGS})
.endfor

pre-build:
.for dir in . quackleio
	@(cd ${WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.endfor

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/quacker \
		${STAGEDIR}${PREFIX}/bin/quackle
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
