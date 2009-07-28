# New ports collection makefile for:	cavezofphear
# Date created:			23 July 2005
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	cavezofphear
PORTVERSION=	0.5
CATEGORIES=	games
MASTER_SITES=	http://www.x86.no/cavezofphear/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	phear-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Boulder Dash / Digger-like game written using ncurses

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
BUILD_WRKSRC=	${WRKDIR}/${DISTNAME}/src

PORTDOCS=	ChangeLog README README-EDITOR TODO

post-patch:
	@${REINPLACE_CMD} -e 's|\./data|${DATADIR}/data|' ${WRKSRC}/src/chk.c
	@${REINPLACE_CMD} -e 's|\./phear|phear|' ${WRKSRC}/README-EDITOR

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/phear ${PREFIX}/bin
	@(cd ${WRKSRC}; ${COPYTREE_SHARE} data ${DATADIR})

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
