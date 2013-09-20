# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	freesweep
PORTVERSION=	0.92
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Minesweeper-style game for text-mode terminals

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-prefsdir=${DATADIR} \
		--with-scoresdir=${DATADIR} \
		--disable-debug-log
ALL_TARGET=	${PORTNAME}

MAN6=		freesweep.6
PORTDOCS=	CHANGES README
PLIST_FILES=	bin/freesweep %%DATADIR%%/sweeprc %%DATADIR%%/sweeptimes
PLIST_DIRS=	%%DATADIR%%

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
