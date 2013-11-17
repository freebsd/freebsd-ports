# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dsnake
PORTVERSION=	3.0.0
PORTREVISION=	3
CATEGORIES=	games linux
MASTER_SITES=	http://bitblaze.com/downloads/
DISTNAME=	${PORTNAME}-linux-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Deluxe Snake - snake clone with frogs and mushrooms

RESTRICTED=	Licence forbids any repacking and reselling

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	allegro xorglibs
WRKSRC=		${WRKDIR}/DeluxeSnake

CONFIG_FILES=	config.dat hiscores.dat stats.dat

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/dsnake

do-install:
.for d in data midi
	@${MKDIR} ${STAGEDIR}${DATADIR}/${d}
	${INSTALL_DATA} ${WRKSRC}/${d}/* ${STAGEDIR}${DATADIR}/${d}
.endfor
.for c in ${CONFIG_FILES}
	@${TOUCH} ${STAGEDIR}${DATADIR}/$c
	@${CHMOD} 666 ${STAGEDIR}${DATADIR}/$c
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/dsnake ${STAGEDIR}${DATADIR}
	${ECHO_CMD} "#!/bin/sh" > ${WRKDIR}/dsnake.sh
	${ECHO_CMD} "cd ${DATADIR} && exec ./dsnake \"\$$@\"" >> ${WRKDIR}/dsnake.sh
	${INSTALL_SCRIPT} ${WRKDIR}/dsnake.sh ${STAGEDIR}${PREFIX}/bin/dsnake
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ReadMe.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
