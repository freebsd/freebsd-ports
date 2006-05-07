# New ports collection makefile for:	cavezofphear
# Date created:			23 July 2005
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	cavezofphear
PORTVERSION=	0.1
CATEGORIES=	games
MASTER_SITES=	http://www.x86.no/cavezofphear/
DISTNAME=	phear-${PORTVERSION}

MAINTAINER=	tlp@liquidx.org
COMMENT=	Boulder Dash / Digger-like game written using ncurses

WRKSRC=		${WRKDIR}/phear-${PORTVERSION}/src
USE_BZIP2=	yes
USE_GMAKE=	yes

PLIST_DIRS=	share/${PORTNAME}/levels share/${PORTNAME}

PLIST_FILES=	bin/phear bin/phear-editor \
		share/${PORTNAME}/gover share/${PORTNAME}/htext \
		share/${PORTNAME}/spgraf share/${PORTNAME}/tdesc \
		share/${PORTNAME}/levels/01 share/${PORTNAME}/levels/02 \
		share/${PORTNAME}/levels/03 share/${PORTNAME}/levels/04 \
		share/${PORTNAME}/levels/05

PORTDOCS=	AUTHORS ChangeLog README README-EDITOR TODO

FIXME=		chk.c main.c splash.c

pre-build:
.for i in ${FIXME}
	${REINPLACE_CMD} -e 's|data/|${DATADIR}/|' ${WRKSRC}/${i}
.endfor
	@${REINPLACE_CMD} -e 's|usage: editor|usage: phear-editor|' \
	${WRKSRC}/editor.c
	@${REINPLACE_CMD} -e 's|./editor|phear-editor|' \
	${WRKSRC}/../README-EDITOR
	@${REINPLACE_CMD} -e 's|./phear|phear|' \
	${WRKSRC}/../README-EDITOR

do-install:
	${MKDIR} ${DATADIR}
	${MKDIR} ${DATADIR}/levels
	${INSTALL_DATA} ${WRKSRC}/../data/gover ${DATADIR}/gover
	${INSTALL_DATA} ${WRKSRC}/../data/htext ${DATADIR}/htext
	${INSTALL_DATA} ${WRKSRC}/../data/spgraf ${DATADIR}/spgraf
	${INSTALL_DATA} ${WRKSRC}/../data/tdesc ${DATADIR}/tdesc
	${INSTALL_DATA} ${WRKSRC}/../data/levels/01 ${DATADIR}/levels/01
	${INSTALL_DATA} ${WRKSRC}/../data/levels/02 ${DATADIR}/levels/02
	${INSTALL_DATA} ${WRKSRC}/../data/levels/03 ${DATADIR}/levels/03
	${INSTALL_DATA} ${WRKSRC}/../data/levels/04 ${DATADIR}/levels/04
	${INSTALL_DATA} ${WRKSRC}/../data/levels/05 ${DATADIR}/levels/05
	${INSTALL_PROGRAM} ${WRKSRC}/../phear ${PREFIX}/bin/phear
	${INSTALL_PROGRAM} ${WRKSRC}/../editor ${PREFIX}/bin/phear-editor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../AUTHORS ${DOCSDIR}/AUTHORS
	${INSTALL_DATA} ${WRKSRC}/../ChangeLog ${DOCSDIR}/ChangeLog
	${INSTALL_DATA} ${WRKSRC}/../README ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/../README-EDITOR ${DOCSDIR}/README-EDITOR
	${INSTALL_DATA} ${WRKSRC}/../TODO ${DOCSDIR}/TODO
.endif

.include <bsd.port.mk>
