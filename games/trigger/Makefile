# New ports collection makefile for:	trigger
# Date created:			31 Mar 2005
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	trigger
PORTVERSION=	0.5.1c
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://0day.icculus.org/mirrors/trigger/
DISTFILES=	trigger-${PORTVERSION}-src${EXTRACT_SUFX} \
		trigger-${PORTVERSION}-data${EXTRACT_SUFX}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A rally car racing game

BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam
LIB_DEPENDS=	openal:${PORTSDIR}/audio/openal \
		physfs:${PORTSDIR}/devel/physfs \
		alut.0:${PORTSDIR}/audio/freealut

USE_X_PREFIX=	yes
USE_SDL=	sdl image
USE_GL=		yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

WRKSRC=		${WRKDIR}/trigger-${PORTVERSION}-src
DATASRC=	${WRKDIR}/trigger-${PORTVERSION}-data

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.4
.endif

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

.include <bsd.port.post.mk>
