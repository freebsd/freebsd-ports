# New ports collection makefile for:	lucidlife
# Date created:		18 Aug 2005
# Whom:			Marcin Wisnicki <mwisnicki+freebsd-ports@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	lucidlife
PORTVERSION=	0.9
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org/~jcspray/LucidLife/ \
		http://icculus.org/~jcspray/LucidLife/

MAINTAINER=	mwisnicki+freebsd-ports@gmail.com
COMMENT=	A GTK2 implementation of Conway's Game of Life

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 gnomevfs2 intlhack
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
