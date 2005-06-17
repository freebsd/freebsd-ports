# New ports collection makefile for:	dsnake
# Date created:				18 Nov 2003
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dsnake
PORTVERSION=	3.0.0
PORTREVISION=	2
CATEGORIES=	games linux
MASTER_SITES=	http://bitblaze.com/downloads/
DISTNAME=	${PORTNAME}-linux-${PORTVERSION}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Deluxe Snake - snake clone with frogs and mushrooms

RUN_DEPENDS=	${LINUXBASE}/usr/lib/liballeg.so.4.0:${PORTSDIR}/devel/linux-allegro

NO_PACKAGE=	Licence forbids any repacking and reselling

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/DeluxeSnake

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/dsnake

do-install:
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC}; ${TAR} -cf - *) | (cd ${DATADIR}; ${TAR} -xf -)
	${TOUCH} ${DATADIR}/config.dat ${DATADIR}/hiscores.dat ${DATADIR}/stats.dat
	${CHMOD} 0666 ${DATADIR}/config.dat ${DATADIR}/hiscores.dat ${DATADIR}/stats.dat
	${ECHO_CMD} "#!/bin/sh" > ${WRKDIR}/dsnake.sh
	${ECHO_CMD} "cd ${DATADIR} && ./dsnake -win" >> ${WRKDIR}/dsnake.sh
	${INSTALL_SCRIPT} ${WRKDIR}/dsnake.sh ${PREFIX}/bin/dsnake

.include <bsd.port.mk>
