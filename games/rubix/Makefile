# New ports collection makefile for:	rubix
# Version required:	1.0.1
# Date created:		19 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	rubix-1.0.1
CATEGORIES=	games
MASTER_SITES=	http://sed.free.fr/rubix/

MAINTAINER=	will@FreeBSD.org

USE_GMAKE=	yes
MAKE_ENV=	GMAKE=${GMAKE}
USE_X_PREFIX=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/rubix ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/rubix
	@${INSTALL_DATA} ${WRKSRC}/module.xm ${PREFIX}/share/rubix
.if !defined(NOPORTDOCS)
.for DOC in AUTHORS BUGS INSTALL NOISE README TODO
	@${INSTALL_DATA} ${WRKSRC}/${DOC} ${PREFIX}/share/rubix
.endfor
	@${ECHO}
	@${ECHO} "Docs are installed in ${PREFIX}/share/rubix."
	@${ECHO}
.endif

.include <bsd.port.mk>
