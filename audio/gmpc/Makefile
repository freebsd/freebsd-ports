# New ports collection makefile for:	gmpc
# Date created:		May 12 2004
# Whom:			Mark Reidel <ports@mark.reidel.info>
#
# $FreeBSD$
#

PORTNAME=	gmpc
PORTVERSION=	0.10.3
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	musicpd

MAINTAINER=	ports@mark.reidel.info
COMMENT=	Tray-aware GTK2 client for musicpd

GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk20 libglade2
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \

CFLAGS+=	-I${PREFIX}/include

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gmpc ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/*.png ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/glade/gmpc.glade ${DATADIR}

.include <bsd.port.mk>
