# New ports collection makefile for:	pp
# Version required:			0.01
# Date created:				21 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1998/08/01 05:00:13 nectar Exp $
#

DISTNAME=	pp-0.01
CATEGORIES=	games
MASTER_SITES=	ftp://www.mps.de/pub/unix/ \
		http://www.nectar.com/distfiles/
DISTFILES=	ppinst-0.01.tar.gz ppsrc-0.01.tar.gz

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	qt\\.1\\.:${PORTSDIR}/x11/qt
BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt

USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/ppsrc

pre-build:
	@ cd ${WRKSRC}; make depend

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/pp ${PREFIX}/bin/pp.bin
	@ ${SED} 's#%%PREFIX%%#${PREFIX}#g' ${FILESDIR}/pp.sh > ${WRKDIR}/pp.sh
	@ ${INSTALL_SCRIPT} ${WRKDIR}/pp.sh ${PREFIX}/bin/pp
	@ ${MKDIR} ${PREFIX}/share/pp
	@ ${INSTALL_DATA} ${WRKDIR}/ppinst/autosave.sav ${PREFIX}/share/pp
	@ ${MKDIR} ${PREFIX}/share/pp/pic
	@ ${INSTALL_DATA} ${WRKDIR}/ppinst/*.gif ${PREFIX}/share/pp/pic
	@ ${MKDIR} ${PREFIX}/share/pp/level
	@ ${INSTALL_DATA} ${WRKDIR}/ppinst/*.map1 ${PREFIX}/share/pp/level
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/pp
.for file in INSTALL LICENSE RULES WARRANTY free-license.html
	@ ${INSTALL_DATA} ${WRKDIR}/ppinst/${file} ${PREFIX}/share/doc/pp
.endfor
.endif

.include <bsd.port.mk>
