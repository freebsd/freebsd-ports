# New ports collection makefile for:	hohlin
# Date created:		2004-08-17
# Whom:			Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	hohlin
PORTVERSION=	1.01
CATEGORIES=	games
#MASTER_SITES=	http://retrospec.sgn.net/download.php?id=63&path=games/hoh/bin/
#requires post to download
MASTER_SITES=	http://skye.ki.iif.hu/~mohacsi/downloads/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${SHORTPORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Remake of the classic spectrum game Head over Heels

WRKSRC=		${WRKDIR}/hoh-install-${PORTVERSION}/

USE_BZIP2=	YES
NO_BUILD=	YES
ONLY_FOR_ARCHS=	i386
SHORTPORTVERSION=${PORTVERSION:C/([0-9]*)\.([0-9]*)/\1\2/}

.include <bsd.port.pre.mk>
.if exists(${LINUXBASE}/lib/libc-2.3.2.so) || defined(WITH_LINUX8)
RUN_DEPENDS+=	${LINUXBASE}/usr/X11R6/lib/libXrandr.so.2:${PORTSDIR}/x11/linux-XFree86-libs
WITH_LINUX8=	YES
.else
USE_LINUX=	YES
.endif

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/data/HoH ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/HoHOriginal.dat ${DATADIR}
	${MKDIR} ${DATADIR}/Sound
	${INSTALL_DATA} ${WRKSRC}/data/Sound/Sound.dat ${DATADIR}/Sound/
	${INSTALL_DATA} ${WRKSRC}/data/Sound/Game.ogg ${DATADIR}/Sound/
	${INSTALL_DATA} ${WRKSRC}/data/Sound/Theme.ogg ${DATADIR}/Sound/
	${SED} -e 's:%%DATADIR%%:${DATADIR}:g' ${FILESDIR}/hoh.sh > \
		${PREFIX}/bin/HoH
	${CHMOD} +x ${PREFIX}/bin/HoH
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
