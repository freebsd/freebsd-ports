# New ports collection makefile for:	gmpc
# Date created:		May 12 2004
# Whom:			Mark Reidel <ports@mark.reidel.info>
#
# $FreeBSD$
#

PORTNAME=	gmpc
PORTVERSION=	0.11.2
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	http://mercury.chem.pitt.edu/~shank/ \
		http://download.qballcow.nl/programs/gmpc/

MAINTAINER=	ports@mark.reidel.info
COMMENT=	Tray-aware GTK2 client for musicpd

GNU_CONFIGURE=	yes
USE_GNOME=	libglade2 gnomevfs2
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \

CFLAGS+=	-I${PREFIX}/include

OPTIONS=	NLS "Native language support" on

.if !defined(WITHOUT_NLS)
PLIST_FILES+=	share/locale/fr/LC_MESSAGES/gmpc.mo
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gmpc ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/*.png ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/glade/*.glade ${DATADIR}
.if !defined(WITHOUT_NLS)
.for language in fr
	${MKDIR} ${LOCALBASE}/share/locale/${language}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${language}.gmo ${PREFIX}/share/locale/${language}/LC_MESSAGES/gmpc.mo
.endfor
.endif

.include <bsd.port.mk>
