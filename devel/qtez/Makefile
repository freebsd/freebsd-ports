# New ports collection makefile for:	qtez
# Version required:			0.52a
# Date created:				14 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1998/05/19 06:56:53 tg Exp $
#

DISTNAME=	QTEZ-v0.52a
PKGNAME=	qtez-0.52a
CATEGORIES=	devel x11
MASTER_SITES=	ftp://qtez.commkey.net/pub/QtEZ/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	andy@icc.surw.chel.su

BROKEN=		fetch

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt\\.1\\.:${PORTSDIR}/x11/qt

USE_GMAKE=	yes
USE_X11=	yes
WRKSRC=		${WRKDIR}/qtez/src

do-install:
	@ ${INSTALL_PROGRAM} ${WRKDIR}/qtez/bin/qtez ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/examples/qtez
	@ cd ${WRKDIR}/qtez/demo; tar cf - . | (cd ${PREFIX}/share/examples/qtez; tar xf - )
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/qtez
.for file in INSTALL KDE.README README TODO
	@ ${INSTALL_DATA} ${WRKDIR}/qtez/${file} ${PREFIX}/share/doc/qtez
.endfor
	@ cd ${WRKDIR}/qtez/docs; tar cf - . | (cd ${PREFIX}/share/doc/qtez; tar xf - )
.endif

.include <bsd.port.mk>
