# New ports collection makefile for:	railroad-rampage
# Date created:		08 Nov 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	railroad-rampage
PORTVERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/
DISTNAME=	RailroadRampage_${PORTVERSION}_Linux

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tower Defence-like Arcade and Strategy combination

BUILD_DEPENDS=	bgdc:${PORTSDIR}/devel/bennugd-core \
		${LOCALBASE}/lib/bennugd/mod_grproc.so:${PORTSDIR}/devel/bennugd-modules
RUN_DEPENDS=	bgdi:${PORTSDIR}/devel/bennugd-core \
		${LOCALBASE}/lib/bennugd/mod_grproc.so:${PORTSDIR}/devel/bennugd-modules

USE_ZIP=	yes
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/RailroadRampage_Linux
SUB_FILES=	${PORTNAME}

PORTDOCS=	ReadMe.txt

DESKTOP_ENTRIES="Railroad Rampage" \
		"Tower Defence-like Arcade and Strategy combination" \
		"${DATADIR}/RailroadRampage.png" \
		"railroad-rampage" \
		"Game;StrategyGame;ArcadeGame;" \
		false

do-build:
	cd ${WRKSRC} && ${SETENV} \
		LD_LIBRARY_PATH=${LOCALBASE}/lib/bennugd \
		BENNUDIR=${LOCALBASE}/lib/bennugd \
		${LOCALBASE}/bin/bgdc RailroadRampage.prg || true

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "Music Sound" ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/traintd.fpg ${WRKSRC}/RailroadRampage.dcb \
		${WRKSRC}/RailroadRampage.png ${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ReadMe.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
