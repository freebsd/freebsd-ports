# New ports collection makefile for:	dopewars
# Version required:		1.4.6
# Date created:			16 May 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	dopewars-1.4.6
CATEGORIES=	games
MASTER_SITES=	http://bellatrix.pcl.ox.ac.uk/~ben/dopewars/

MAINTAINER=	jim@FreeBSD.org

USE_GMAKE=	yes

do-build:
	@(cd ${WRKSRC} && ${GMAKE})

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/dopewars ${PREFIX}/bin

post-install:
	@${ECHO} "===>   Installing documentation into ${PREFIX}/share/doc/dopewars"
	@${MKDIR} ${PREFIX}/share/doc/dopewars && ${CHMOD} a+rx ${PREFIX}/share/doc/dopewars
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dopewars
	@${INSTALL_DATA} ${WRKSRC}/*.html ${PREFIX}/share/doc/dopewars
	@${ECHO} "===>   Run 'dopewars -h' for usage options."

.include <bsd.port.mk>
