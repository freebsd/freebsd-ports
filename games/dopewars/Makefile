# New ports collection makefile for:	dopewars
# Date created:			16 May 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dopewars
PORTVERSION=	1.5.9
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://bellatrix.pcl.ox.ac.uk/~ben/dopewars/
MASTER_SITE_SUBDIR=	dopewars

MAINTAINER=	petef@FreeBSD.org
COMMENT=	A UNIX rewrite of a game originally based on "Drug Wars"

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

CONFIGURE_ARGS=	--enable-networking --disable-plugins
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS=yes
.endif

MAN6=	dopewars.6

post-patch:
	@${REINPLACE_CMD} -e 's!/pixmaps!/dopewars/pixmaps!' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's!dopewars.sco!dopewars/dopewars.sco!g' \
		${WRKSRC}/src/dopewars.c ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's!^CFLAGS =!CFLAGS = \@GLIB_CFLAGS\@!' \
		${WRKSRC}/src/gui_client/Makefile.in \
		${WRKSRC}/src/curses_client/Makefile.in

.include <bsd.port.mk>
