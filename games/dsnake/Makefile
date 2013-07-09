# New ports collection makefile for:	dsnake
# Date created:				18 Nov 2003
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

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

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	CONFIG_FILES="config.dat hiscores.dat stats.dat"

PORTDOCS=	*

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/dsnake

do-install:
.for d in data midi
	${MKDIR} ${DATADIR}/${d}
	${INSTALL_DATA} ${WRKSRC}/${d}/* ${DATADIR}/${d}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/dsnake ${DATADIR}
	${ECHO_CMD} "#!/bin/sh" > ${WRKDIR}/dsnake.sh
	${ECHO_CMD} "cd ${DATADIR} && exec ./dsnake \"\$$@\"" >> ${WRKDIR}/dsnake.sh
	${INSTALL_SCRIPT} ${WRKDIR}/dsnake.sh ${PREFIX}/bin/dsnake
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ReadMe.txt ${DOCSDIR}
.endif
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
