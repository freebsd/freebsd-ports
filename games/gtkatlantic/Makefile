# New ports collection makefile for:	gtkatlantic
# Date created:		2005-03-17
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports-stable/games/gtkatlantic/Makefile,v 1.1 2006/03/04 21:36:29 ahze Exp $

PORTNAME=	gtkatlantic
PORTVERSION=	0.4.2
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://download.tuxfamily.org/gtkatlantic/downloads/v0.4/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GtkAtlantic is a game like Monopoly(tm)

USE_BZIP2=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|mkdir |${MKDIR} |' \
		${WRKSRC}/Makefile.in ${WRKSRC}/configure

.include <bsd.port.mk>
