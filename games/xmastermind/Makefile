# New ports collection makefile for:	xmastermind
# Version required:			0.1
# Date created:				23 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.5 1998/09/26 23:18:05 steve Exp $
#

DISTNAME=		xmastermind-0.1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy

MAINTAINER=		andy@icc.surw.chel.su

LIB_DEPENDS=		xforms.0:${PORTSDIR}/x11-toolkits/xforms

USE_X_PREFIX=		yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xmastermind ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/doc/xmastermind
.for file in BUGS README.for.developers README.for.users
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/xmastermind
.endfor

.include <bsd.port.mk>
