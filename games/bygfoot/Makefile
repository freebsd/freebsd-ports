# New ports collection makefile for:	bygfoot
# Date created:				6th July 2004
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bygfoot
PORTVERSION=	1.8.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Football (soccer) management game

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20 gnometarget
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

MAN6=		bygfoot.6

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' ${WRKSRC}/b-u/bygfoot-update

.include <bsd.port.mk>
