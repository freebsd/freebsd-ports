# New ports collection makefile for:	wargus
# Date created:			1 Jul 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	wargus
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	tlp@liquidx.org
COMMENT=	Warcraft2 Mod that allows you to play Warcraft2 with Stratagus

BUILD_DEPENDS=	${LOCALBASE}/lib/libpng.a:${PORTSDIR}/graphics/png
RUN_DEPENDS=	${LOCALBASE}/bin/stratagus:${PORTSDIR}/games/stratagus

USE_GMAKE=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-install:
	${MKDIR} ${PREFIX}/share/wargus
	${MKDIR} ${PREFIX}/share/wargus/campaigns
	${MKDIR} ${PREFIX}/share/wargus/campaigns/human
	${MKDIR} ${PREFIX}/share/wargus/campaigns/human-exp
	${MKDIR} ${PREFIX}/share/wargus/campaigns/orc
	${MKDIR} ${PREFIX}/share/wargus/campaigns/orc-exp
	${MKDIR} ${PREFIX}/share/wargus/contrib
	${MKDIR} ${PREFIX}/share/wargus/maps
	${MKDIR} ${PREFIX}/share/wargus/maps/multi
	${MKDIR} ${PREFIX}/share/wargus/scripts
	${MKDIR} ${PREFIX}/share/wargus/scripts/ai
	${MKDIR} ${PREFIX}/share/wargus/scripts/human
	${MKDIR} ${PREFIX}/share/wargus/scripts/orc
	${MKDIR} ${PREFIX}/share/wargus/scripts/tilesets
	${INSTALL_DATA} ${WRKSRC}/campaigns/human/* ${PREFIX}/share/wargus/campaigns/human
	${INSTALL_DATA} ${WRKSRC}/campaigns/human-exp/* ${PREFIX}/share/wargus/campaigns/human-exp
	${INSTALL_DATA} ${WRKSRC}/campaigns/orc/* ${PREFIX}/share/wargus/campaigns/orc
	${INSTALL_DATA} ${WRKSRC}/campaigns/orc-exp/* ${PREFIX}/share/wargus/campaigns/orc-exp
	${INSTALL_DATA} ${WRKSRC}/contrib/* ${PREFIX}/share/wargus/contrib
	${INSTALL_DATA} ${WRKSRC}/maps/multi/* ${PREFIX}/share/wargus/maps/multi
	${INSTALL_DATA} ${WRKSRC}/scripts/*.lua ${PREFIX}/share/wargus/scripts
	${INSTALL_DATA} ${WRKSRC}/scripts/ai/* ${PREFIX}/share/wargus/scripts/ai
	${INSTALL_DATA} ${WRKSRC}/scripts/human/* ${PREFIX}/share/wargus/scripts/human
	${INSTALL_DATA} ${WRKSRC}/scripts/orc/* ${PREFIX}/share/wargus/scripts/orc
	${INSTALL_DATA} ${WRKSRC}/scripts/tilesets/* ${PREFIX}/share/wargus/scripts/tilesets
	${INSTALL_SCRIPT} ${WRKSRC}/build.sh ${PREFIX}/share/wargus/build.sh
	${INSTALL_PROGRAM} ${WRKSRC}/wartool ${PREFIX}/share/wargus/wartool
	${INSTALL_SCRIPT} ${WRKDIR}/wargus ${PREFIX}/bin/wargus

post-build:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/Makefile
	@(cp ${FILESDIR}/wargus.in ${WRKDIR}/wargus)
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKDIR}/wargus
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
