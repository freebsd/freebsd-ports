# New ports collection makefile for:	wargus
# Date created:			1 Jul 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	wargus
PORTVERSION=	2.1
PORTREVISION=	2
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

PKGMESSAGE=	${WRKDIR}/pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^\(CC\)|#\1|; \
		s|^\(CFLAGS =\)|\1 ${CFLAGS}|; \
		s|\/usr\/local\(\/cross\)|${PREFIX}\1|; \
		s|\(-I\)\/usr\/local|\1${LOCALBASE}|; \
		s|\(-L\)\/usr\/local|\1${LOCALBASE}|' \
		${WRKSRC}/Makefile

do-install:
	${MKDIR} ${DATADIR}
	${MKDIR} ${DATADIR}/campaigns
	${MKDIR} ${DATADIR}/campaigns/human
	${MKDIR} ${DATADIR}/campaigns/human-exp
	${MKDIR} ${DATADIR}/campaigns/orc
	${MKDIR} ${DATADIR}/campaigns/orc-exp
	${MKDIR} ${DATADIR}/contrib
	${MKDIR} ${DATADIR}/maps
	${MKDIR} ${DATADIR}/maps/multi
	${MKDIR} ${DATADIR}/scripts
	${MKDIR} ${DATADIR}/scripts/ai
	${MKDIR} ${DATADIR}/scripts/human
	${MKDIR} ${DATADIR}/scripts/orc
	${MKDIR} ${DATADIR}/scripts/tilesets
	${INSTALL_DATA} ${WRKSRC}/campaigns/human/* ${DATADIR}/campaigns/human
	${INSTALL_DATA} ${WRKSRC}/campaigns/human-exp/* ${DATADIR}/campaigns/human-exp
	${INSTALL_DATA} ${WRKSRC}/campaigns/orc/* ${DATADIR}/campaigns/orc
	${INSTALL_DATA} ${WRKSRC}/campaigns/orc-exp/* ${DATADIR}/campaigns/orc-exp
	${INSTALL_DATA} ${WRKSRC}/contrib/* ${DATADIR}/contrib
	${INSTALL_DATA} ${WRKSRC}/maps/multi/* ${DATADIR}/maps/multi
	${INSTALL_DATA} ${WRKSRC}/scripts/*.lua ${DATADIR}/scripts
	${INSTALL_DATA} ${WRKSRC}/scripts/ai/* ${DATADIR}/scripts/ai
	${INSTALL_DATA} ${WRKSRC}/scripts/human/* ${DATADIR}/scripts/human
	${INSTALL_DATA} ${WRKSRC}/scripts/orc/* ${DATADIR}/scripts/orc
	${INSTALL_DATA} ${WRKSRC}/scripts/tilesets/* ${DATADIR}/scripts/tilesets
	${INSTALL_SCRIPT} ${WRKSRC}/build.sh ${DATADIR}/build.sh
	${INSTALL_PROGRAM} ${WRKSRC}/wartool ${DATADIR}/wartool
	${INSTALL_SCRIPT} ${WRKDIR}/wargus ${PREFIX}/bin/wargus

post-build:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/Makefile
	@(cp ${FILESDIR}/wargus.in ${WRKDIR}/wargus)
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKDIR}/wargus
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
