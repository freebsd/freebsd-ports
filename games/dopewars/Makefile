# New ports collection makefile for:	dopewars
# Date created:			16 May 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dopewars
PORTVERSION=	1.5.8
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://bellatrix.pcl.ox.ac.uk/~ben/dopewars/
MASTER_SITE_SUBDIR=	dopewars

MAINTAINER=	petef@FreeBSD.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

CONFIGURE_ARGS+=	--enable-nls --enable-networking --disable-plugins

.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS=yes
.endif

PLIST_SUB=	DOPEWARS=${PKGNAME}

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
