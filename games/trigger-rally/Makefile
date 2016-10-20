# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	trigger-rally
PORTVERSION=	0.6.1
DISTVERSIONSUFFIX=	-src
CATEGORIES=	games
MASTER_SITES=	SF/trigger-rally/trigger-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rally car racing game

BUILD_DEPENDS=	jam:devel/jam
LIB_DEPENDS=	libphysfs.so:devel/physfs
RUN_DEPENDS=	${DATADIR}/trigger.config.defs:games/trigger-data

USES=		openal:al,alut tar:bzip2
USE_SDL=	sdl image
USE_GL=		glu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR} \
		--with-libAlut=${LOCALBASE} \
		--with-libPhysFS=${LOCALBASE}

DESKTOP_ENTRIES="Trigger" "" "trigger" \
		"trigger" "" false

PLIST_FILES=	bin/trigger
PORTDOCS=	README-stereo.txt README.txt

OPTIONS_DEFINE=	DOCS

do-build:
	@cd ${BUILD_WRKSRC} && ${LOCALBASE}/bin/jam

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trigger ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
