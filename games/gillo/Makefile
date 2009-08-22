# New ports collection makefile for:	gillo
# Date created:				23 Jan 2006
# Whom:					Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	gillo
DISTVERSION=	1.0beta1
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.0beta1
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Players are cars throwing a magnetic fuzzy ball into a goal

BUILD_DEPENDS=	${JAM}:${PORTSDIR}/devel/jam \
		${LOCALBASE}/lib/libode.a:${PORTSDIR}/devel/ode \
		${LOCALBASE}/lib/libplibsg.a:${PORTSDIR}/x11-toolkits/plib

USE_BZIP2=	yes
USE_GL=		gl
USE_SDL=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

JAM?=		${LOCALBASE}/bin/jam

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|SDL/||g' ${WRKSRC}/src/*
	@${REINPLACE_CMD} -e 's|%%SDL_CFLAGS%%|`${SDL_CONFIG} --cflags`|' \
		${WRKSRC}/Jamrules
	@${REINPLACE_CMD} -e 's|%%SDL_LDFLAGS%%|`${SDL_CONFIG} --libs`|' \
		${WRKSRC}/src/Jamfile

do-build:
	cd ${WRKSRC} && ${SETENV} "C++=${CC}" "LOCALBASE=${LOCALBASE}" \
		"CFLAGS=${CFLAGS} -DDATADIR=\\\"${PREFIX}/share\\\"" \
	${JAM} -dx -sPREFIX=${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gillo3 ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/*.* ${DATADIR}

.include <bsd.port.mk>
