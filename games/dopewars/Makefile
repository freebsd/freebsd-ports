# New ports collection makefile for:	dopewars
# Date created:			16 May 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dopewars
PORTVERSION=	1.5.0
CATEGORIES=	games
MASTER_SITES=	http://dopewars.sourceforge.net/ \
		http://bellatrix.pcl.ox.ac.uk/~ben/dopewars/

MAINTAINER=	jim@FreeBSD.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GTK=	yes
USE_X_PREFIX=	yes

CONFIGURE_ARGS=	--enable-nls

post-install:
	@${ECHO} "===>   Documentation is installed in ${PREFIX}/share/doc/dopewars"
	@${ECHO} "===>   Run 'dopewars -h' for usage options."

.include <bsd.port.mk>
