# New ports collection makefile for:	dopewars
# Date created:			16 May 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dopewars
PORTVERSION=	1.5.1
CATEGORIES=	games
MASTER_SITES=	http://dopewars.sourceforge.net/ \
		http://bellatrix.pcl.ox.ac.uk/~ben/dopewars/

MAINTAINER=	petef@databits.net

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GTK=	yes
USE_X_PREFIX=	yes

CONFIGURE_ARGS=	--enable-nls

DOPEWARS=	${PKGNAME}
PLIST_SUB=	DOPEWARS=${DOPEWARS}

.include <bsd.port.mk>
