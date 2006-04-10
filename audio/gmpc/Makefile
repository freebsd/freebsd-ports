# New ports collection makefile for:	gmpc
# Date created:		May 12 2004
# Whom:			Mark Reidel <ports@mark.reidel.info>
#
# $FreeBSD$
#

PORTNAME=	gmpc
PORTVERSION=	0.13.0
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.qballcow.nl/programs/gmpc-0.13/

MAINTAINER=	redchrom@gmail.com
COMMENT=	Tray-aware GTK2 client for musicpd

LIB_DEPENDS=	mpd:${PORTSDIR}/audio/libmpd

GNU_CONFIGURE=	yes
USE_GNOME=	libglade2 gnomevfs2
USE_X_PREFIX=	yes

OPTIONS=	NLS "Native language support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_FILES+=	share/locale/fr/LC_MESSAGES/gmpc.mo
PLIST_FILES+=	share/locale/ru/LC_MESSAGES/gmpc.mo
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/data/Makefile.in

post-install:
.if !defined(WITHOUT_NLS)
.for language in fr ru
	${MKDIR} ${LOCALBASE}/share/locale/${language}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${language}.gmo ${PREFIX}/share/locale/${language}/LC_MESSAGES/gmpc.mo
.endfor
.endif

.include <bsd.port.post.mk>
