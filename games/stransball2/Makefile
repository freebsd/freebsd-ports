# New ports collection makefile for:	stransball2
# Date created:		07 Apr 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	stransball2
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/ \
		http://braingames.bugreport.nl/stransball2/
DISTNAME=	${PORTNAME}-v${PORTVERSION:C/\.//}-linux

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A sequel to Transball and Transball 2 THRUST-type games

LIB_DEPENDS=	SGE.0:${PORTSDIR}/devel/sdl_sge

USE_ZIP=	yes
USE_GMAKE=	yes
USE_SDL=	sdl image mixer sound

BUILD_WRKSRC=	${WRKSRC}/sources

PORTDOCS=	readme.txt

post-extract:
	@${RM} -f ${WRKSRC}/sound/WS_FTP.LOG

post-patch:
	@${FIND} ${BUILD_WRKSRC} -name '*.cpp' | ${XARGS} ${REINPLACE_CMD} \
		-e 's|demos/|${DATADIR}/&|g; s|graphics/|${DATADIR}/&|g; \
		s|maps/|${DATADIR}/&|g; s|sound/|${DATADIR}/&|g; \
	       	s|"maps"|"${DATADIR}/maps"|g'

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/stransball2 ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} 'graphics sound maps demos' ${DATADIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
