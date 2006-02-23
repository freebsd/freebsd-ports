# New ports collection makefile for:	gtkatlantic
# Date created:		2005-03-17
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkatlantic
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://gtkatlantic.gradator.net/downloads/v0.4/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	GtkAtlantic is a game like Monopoly(tm)

USE_BZIP2=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|mkdir |${MKDIR} |' \
		${WRKSRC}/Makefile.in ${WRKSRC}/configure

.include <bsd.port.mk>
