# New ports collection makefile for:	dopewars
# Version required:		1.4.2
# Date created:			16 May 1999
# Whom:				Jim Mock <jim@phrantic.phear.net>
#
# $Id$
#

DISTNAME=	dopewars-1.4.2
CATEGORIES=	games
MASTER_SITES=	http://bellatrix.pcl.ox.ac.uk/~ben/dopewars/

MAINTAINER=	jim@phrantic.phear.net

USE_GMAKE=	yes

do-build:
	(cd ${WRKSRC} && ${GMAKE})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dopewars ${PREFIX}/bin

post-install:
	@${ECHO} "		"
	@${ECHO} "===> Run 'dopewars -h' for usage options."
	@${ECHO} "		"

.include <bsd.port.mk>
