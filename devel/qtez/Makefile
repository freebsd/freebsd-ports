# New ports collection makefile for:	qtez
# Version required:			0.62a
# Date created:				14 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.4 1998/07/02 00:09:31 asami Exp $
#

DISTNAME=	QTEZ-v0.62a
PKGNAME=	qtez-0.62a
CATEGORIES=	devel x11
MASTER_SITES=	ftp://qtez.commkey.net/pub/QtEZ/ \
		ftp://qtez.commkey.net/pub/QtEZ/old/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	andy@icc.surw.chel.su

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt\\.1\\.:${PORTSDIR}/x11/qt

BROKEN=		fetch

USE_GMAKE=	yes
USE_X11=	yes
WRKSRC=		${WRKDIR}/qtez

do-install:
	@ ${INSTALL_PROGRAM} ${WRKDIR}/qtez/bin/qtez ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/examples/qtez
	@ cd ${WRKDIR}/qtez/demo; tar cf - . | (cd ${PREFIX}/share/examples/qtez; tar xf - )
	@ ${MKDIR} ${PREFIX}/share/qtez
	@ ${INSTALL_DATA} ${WRKSRC}/lib/demo/progress/progress.qtl ${PREFIX}/share/qtez
	@ ${INSTALL_DATA} ${WRKSRC}/lib/demo/tableview/tableview.qtl ${PREFIX}/share/qtez
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/qtez
.for file in INSTALL KDE.README README TODO
	@ ${INSTALL_DATA} ${WRKDIR}/qtez/${file} ${PREFIX}/share/doc/qtez
.endfor
	@ cd ${WRKDIR}/qtez/docs; tar cf - . | (cd ${PREFIX}/share/doc/qtez; tar xf - )
.endif

.include <bsd.port.mk>
