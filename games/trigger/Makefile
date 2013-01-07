# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	trigger
PORTVERSION=	0.6.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}-rally/${PORTNAME}-rally/${PORTNAME}-${PORTVERSION}
DISTFILES=	trigger-rally-${PORTVERSION}-src${EXTRACT_SUFX} \
		trigger-rally-${DATAVERSION}-data${EXTRACT_SUFX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Rally car racing game

BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam
LIB_DEPENDS=	physfs.1:${PORTSDIR}/devel/physfs

USE_OPENAL=	al alut
USE_SDL=	sdl image
USE_GL=		glu
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

WRKSRC=		${WRKDIR}/trigger-rally-${PORTVERSION}-src
DATASRC=	${WRKDIR}/trigger-rally-${DATAVERSION}-data

DATAVERSION=	0.6.0

DESKTOP_ENTRIES="Trigger" "${COMMENT}" "" \
		"trigger" "" false

PORTDOCS=	README-stereo.txt README.txt

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|SDL/||' \
		${WRKSRC}/src/trigger/main.cpp \
		${WRKSRC}/src/pengine/texture.cpp
	@${REINPLACE_CMD} -e 's|\$${prefix}/share|${DATADIR}|; \
		s|-lopenal|& -lalut|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O3||' ${WRKSRC}/Jamrules

do-build:
	@cd ${BUILD_WRKSRC} && ${LOCALBASE}/bin/jam

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/trigger ${PREFIX}/bin

	${MKDIR} ${DATADIR}
.for d in events fonts maps plugins sounds textures vehicles
	cd ${DATASRC} && ${COPYTREE_SHARE} ${d} ${DATADIR}
.endfor
	${INSTALL_DATA} ${DATASRC}/trigger.config.defs ${DATADIR}

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
