# Created by: Göran Runfeldt <goranrunfeldt@home.se>
# $FreeBSD$

PORTNAME=	xtux
PORTVERSION=	20030306
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	mmokhi@FreeBSD.org
COMMENT=	Humorous Arcade game for X

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake xorg
USE_XORG=	xpm
MAKE_ENV=	CPP="${CC} -E"

CFLAGS+=	-DDATADIR=\\\"${DATADIR}\\\"

MAKE_JOBS_UNSAFE=yes

PLIST_FILES=	bin/tux_serv bin/xtux
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${FIND} ${WRKSRC}/src -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^CC|#CC|g ; \
		 s|^CFLAGS|#CFLAGS|g ; \
		 s|^CPP|#CPP|g ; \
		 s|^MAKE|#MAKE|g ; \
		 s|/usr/X11R6|$${LOCALBASE}|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtux ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tux_serv ${STAGEDIR}${PREFIX}/bin

	@${MKDIR} ${STAGEDIR}${DATADIR}/demos
	@${MKDIR} ${STAGEDIR}${DATADIR}/images/entities
	@${MKDIR} ${STAGEDIR}${DATADIR}/images/events
	@${MKDIR} ${STAGEDIR}${DATADIR}/images/items
	@${MKDIR} ${STAGEDIR}${DATADIR}/images/weapons
	@${MKDIR} ${STAGEDIR}${DATADIR}/images/tiles
	@${MKDIR} ${STAGEDIR}${DATADIR}/maps

	${INSTALL_DATA} ${WRKSRC}/data/*.table ${STAGEDIR}${DATADIR}
.for file in ascii.txt bios entities weapons
	${INSTALL_DATA} ${WRKSRC}/data/${file} ${STAGEDIR}${DATADIR}
.endfor
.for dir in entities events items weapons tiles .
	${INSTALL_DATA} ${WRKSRC}/data/images/${dir}/*.xpm \
		${STAGEDIR}${DATADIR}/images/${dir}
.endfor
	${INSTALL_DATA} ${WRKSRC}/data/demos/*.xtdem ${STAGEDIR}${DATADIR}/demos
	${INSTALL_DATA} ${WRKSRC}/data/maps/*.map ${STAGEDIR}${DATADIR}/maps

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
