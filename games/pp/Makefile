# New ports collection makefile for:	pp
# Date created:				21 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	pp
PORTVERSION=	0.01
CATEGORIES=	games
MASTER_SITES=	ftp://www.mps.de/pub/unix/
DISTFILES=	ppinst-0.01.tar.gz ppsrc-0.01.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Prometeus Project - real time strategy game for X Window System

WRKSRC=		${WRKDIR}/ppsrc
USE_GCC=	2.95
USE_QT_VER=	1
USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pp ${PREFIX}/bin/pp.bin
	@${SED} "s:%%PREFIX%%:${PREFIX}:g" ${FILESDIR}/pp.sh > ${WRKDIR}/pp.sh
	${INSTALL_SCRIPT} ${WRKDIR}/pp.sh ${PREFIX}/bin/pp
	@${MKDIR} ${PREFIX}/share/pp
	${INSTALL_DATA} ${WRKDIR}/ppinst/autosave.sav ${PREFIX}/share/pp
	@${MKDIR} ${PREFIX}/share/pp/pic
	${INSTALL_DATA} ${WRKDIR}/ppinst/*.gif ${PREFIX}/share/pp/pic
	@${MKDIR} ${PREFIX}/share/pp/level
	${INSTALL_DATA} ${WRKDIR}/ppinst/*.map1 ${PREFIX}/share/pp/level
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/pp
.for file in INSTALL LICENSE RULES WARRANTY free-license.html
	${INSTALL_DATA} ${WRKDIR}/ppinst/${file} ${PREFIX}/share/doc/pp
.endfor
.endif

.include <bsd.port.mk>
