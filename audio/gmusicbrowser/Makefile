# New ports collection makefile for:	gmusicbrowser
# Date created:		2011-10-13
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gmusicbrowser
PORTVERSION=	1.1.8
CATEGORIES=	audio
MASTER_SITES=	http://gmusicbrowser.org/download/

MAINTAINER=	lichray@gmail.com
COMMENT=	Jukebox for large collections of mp3/ogg/flac/mpc files

RUN_DEPENDS=	p5-Gtk2>=1.0:${PORTSDIR}/x11-toolkits/p5-Gtk2

MAN1=	gmusicbrowser.1
PORTDOCS=	AUTHORS COPYING README NEWS INSTALL layout_doc.html
PORTDATA=	*

OPTIONS=	GST	"Enable GStreamer backend"	Off \
		MPLAYER	"Enable mplayer backend"	On \
		DBUS	"Enable DBus (Gnome multimedia key)" Off \
		WEBKIT	"Enable embedded web browser" Off \
		NLS	"Enable Native Language Support" On
#		123	"Enable mpg123/ogg123 backend"	Off  # alsa-only

.include <bsd.port.pre.mk>

.if defined(WITH_GST)
RUN_DEPENDS+=	p5-GStreamer>=0:${PORTSDIR}/multimedia/p5-GStreamer
.endif

.if defined(WITH_MPLAYER)
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if defined(WITH_DBUS)
RUN_DEPENDS+=	p5-Net-DBus>=1.0:${PORTSDIR}/devel/p5-Net-DBus
.endif

.if defined(WITH_WEBKIT)
RUN_DEPENDS+=	p5-Gtk2-WebKit>=0:${PORTSDIR}/www/p5-Gtk2-WebKit
.endif

.if defined(NOPORTDATA)
IGNORE=		port data contain code, undefine NOPORTDATA
.endif

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man ${MANPREFIX}/man/man1/${MAN1}
	@${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${DESKTOPDIR}
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && (for d in layouts pix plugins; do \
		${COPYTREE_SHARE} $$d ${DATADIR}; done) && \
		${INSTALL_DATA} *.pm ${DATADIR} && \
		${INSTALL_SCRIPT} iceserver.pl ${DATADIR})
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif
.if !defined(WITHOUT_NLS)
	(cd ${WRKSRC}/locale && \
		${COPYTREE_SHARE} \* ${PREFIX}/share/locale)
	(cd ${WRKSRC} && \
		${FIND} locale -type f | ${SED} "s|^|share/|g" >> ${TMPPLIST})
.endif

.include <bsd.port.post.mk>
