# New ports collection makefile for:	gtkatlantic
# Date created:		2005-03-17
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports-stable/games/gtkatlantic/Makefile,v 1.1 2006/03/04 21:36:29 ahze Exp $

PORTNAME=	gtkatlantic
PORTVERSION=	0.4.3
CATEGORIES=	games
MASTER_SITES=	http://download.tuxfamily.org/gtkatlantic/downloads/v0.4/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A game like Monopoly(tm)

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e '/-Werror/s|^|#|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|mkdir |$$(mkdir_p) |g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
