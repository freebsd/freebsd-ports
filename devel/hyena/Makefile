# New ports collection makefile for:	hyena
# Date created:		2009-08-19
# Whom:			Romain Tartiere <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	hyena
PORTVERSION=	0.3
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Library of GUI and non-GUI C-sharp code

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtksharp20

post-patch:
	@${REINPLACE_CMD} -e 's|@libdir@/pkgconfig|@libdir@/../libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.include \
		${WRKSRC}/src/Hyena.Gui/Makefile.in \
		${WRKSRC}/src/Hyena.Data.Sqlite/Makefile.in \
		${WRKSRC}/src/Mono.Data.Sqlite/Makefile.in \
		${WRKSRC}/src/Hyena/Makefile.in \

.include <bsd.port.mk>
