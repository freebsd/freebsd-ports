# New ports collection makefile for:	3Dc
# Version required:			0.8.1
# Date created:				2 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1998/05/03 23:27:36 mph Exp $
#

DISTNAME=		3Dc-0.8.1
PKGNAME=		3dc-0.8.1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy

MAINTAINER=		andy@icc.surw.chel.su

LIB_DEPENDS=		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
			Xaw3d\\.6\\.:${PORTSDIR}/x11/Xaw3d

USE_X11=		yes
WRKSRC=			${WRKDIR}/3Dc

do-build:
	@ cd ${WRKSRC}/src; make

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/3Dc ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/3Dc
.for file in 3Dc-rules.html ACKNOWLEDGEMENTS GPL README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/3Dc
.endfor
.endif

.include <bsd.port.mk>
