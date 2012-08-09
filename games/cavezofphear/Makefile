# New ports collection makefile for:	cavezofphear
# Date created:			23 July 2005
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	cavezofphear
PORTVERSION=	0.5.1
CATEGORIES=	games
MASTER_SITES=	http://www.x86.no/cavezofphear/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	phear-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Boulder Dash / Digger-like game written using ncurses

LICENSE=	GPLv3 # (or later)

OPTIONS_DEFINE=	DOCS

BUILD_WRKSRC=	${WRKDIR}/${DISTNAME}/src

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	phear
MAKE_JOBS_SAFE=	yes

PORTDOCS=	ChangeLog README README-EDITOR TODO

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|\./data|${DATADIR}/data|' ${WRKSRC}/src/chk.c
	@${REINPLACE_CMD} -e 's|\./phear|phear|' ${WRKSRC}/README-EDITOR

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/phear ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}; ${COPYTREE_SHARE} data ${DATADIR})
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
