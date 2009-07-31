# New ports collection makefile for:	trigger
# Date created:			31 Mar 2005
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	trigger
PORTVERSION=	0.5.2.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=${PORTNAME}-rally
DISTFILES=	trigger-${PORTVERSION}-src${EXTRACT_SUFX} \
		trigger-${DATAVERSION}-data${EXTRACT_SUFX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A rally car racing game

BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam
LIB_DEPENDS=	openal:${PORTSDIR}/audio/openal \
		physfs.1:${PORTSDIR}/devel/physfs \
		alut.1:${PORTSDIR}/audio/freealut

USE_SDL=	sdl image
USE_GL=		yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

WRKSRC=		${WRKDIR}/trigger-${PORTVERSION}-src
DATASRC=	${WRKDIR}/trigger-${DATAVERSION}-data

DATAVERSION=	0.5.2

DESKTOP_ENTRIES="Trigger" "Car racing game" "" \
		"trigger" "" false

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
.for d in events maps plugins sounds textures vehicles
	${CP} -R ${DATASRC}/${d} ${DATADIR}
.endfor
	${INSTALL_DATA} ${DATASRC}/trigger.config.defs ${DATADIR}

	-${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}/*
	${FIND} ${DATADIR}/* -type f -exec ${CHMOD} 444 {} \;
	${FIND} ${DATADIR}/* -type d -exec ${CHMOD} 555 {} \;

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in README-stereo.txt README.txt
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
