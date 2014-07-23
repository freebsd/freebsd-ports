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

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-prefsdir=${DATADIR} \
		--with-scoresdir=${DATADIR} \
		--disable-debug-log
ALL_TARGET=	${PORTNAME}

PORTDOCS=	CHANGES README
PLIST_FILES=	bin/${PORTNAME} man/man6/${PORTNAME}.6.gz \
		%%DATADIR%%/sweeprc %%DATADIR%%/sweeptimes
PLIST_DIRS=	%%DATADIR%%

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
