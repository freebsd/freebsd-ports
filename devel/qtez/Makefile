# New ports collection makefile for:	qtez
# Version required:			0.77a
# Date created:				14 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.9 1998/08/12 06:29:26 asami Exp $
#

DISTNAME=	QtEZ.current-src
PKGNAME=	qtez-0.77a
CATEGORIES=	devel
MASTER_SITES=	http://qtez.zax.net/qtez-extras/
#EXTRACT_SUFX=	tar.gz

MAINTAINER=	andy@icc.surw.chel.su

USE_QT=		yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/qtez_src

do-install:
	@ ${INSTALL_PROGRAM} ${WRKDIR}/qtez_src/bin/qtez ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/examples/qtez
	@ cd ${WRKDIR}/qtez_src/demo; tar cf - . | (cd ${PREFIX}/share/examples/qtez; tar xf - )

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/qtez
.for file in INSTALL KDE.README README TODO
	@ ${INSTALL_DATA} ${WRKDIR}/qtez_src/${file} ${PREFIX}/share/doc/qtez
.endfor
	@ cd ${WRKDIR}/qtez_src/docs; tar cf - . | (cd ${PREFIX}/share/doc/qtez; tar xf - )
.endif

.include <bsd.port.mk>
