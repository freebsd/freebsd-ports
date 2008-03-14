# New ports collection makefile for:	bygfoot
# Date created:				6th July 2004
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bygfoot
PORTVERSION=	2.2.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Football (soccer) management game

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20 gnometarget
USE_XLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.mk>
