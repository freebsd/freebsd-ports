# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	gmusicbrowser
PORTVERSION=	1.1.10
CATEGORIES=	audio
MASTER_SITES=	http://gmusicbrowser.org/download/

MAINTAINER=	lichray@gmail.com
COMMENT=	Jukebox for large collections of mp3/ogg/flac/mpc files

RUN_DEPENDS=	p5-Gtk2>=1.0:${PORTSDIR}/x11-toolkits/p5-Gtk2

NO_BUILD=	yes
NO_STAGE=	yes

MAN1=		gmusicbrowser.1
PORTDOCS=	AUTHORS COPYING README NEWS INSTALL layout_doc.html
PORTDATA=	*

OPTIONS_DEFINE=	GSTREAMER MPLAYER DBUS WEBKIT NLS LIBNOTIFY
OPTIONS_DEFAULT=MPLAYER
LIBNOTIFY_DESC=	Desktop notification

WEBKIT_DESC=	Enable embedded web browser

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGSTREAMER}
RUN_DEPENDS+=	p5-GStreamer>=0:${PORTSDIR}/multimedia/p5-GStreamer
.endif

.if ${PORT_OPTIONS:MMPLAYER}
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if ${PORT_OPTIONS:MDBUS}
RUN_DEPENDS+=	p5-Net-DBus>=1.0:${PORTSDIR}/devel/p5-Net-DBus
.endif

.if ${PORT_OPTIONS:MWEBKIT}
RUN_DEPENDS+=	p5-Gtk2-WebKit>=0:${PORTSDIR}/www/p5-Gtk2-WebKit
.endif

.if ${PORT_OPTIONS:MLIBNOTIFY}
RUN_DEPENDS+=	pt-Gtk2-Notify>=0.05:${PORTSDIR}/devel/p5-Gtk2-Notify
.endif

.if defined(NOPORTDATA)
IGNORE=		port data contain code, undefine NOPORTDATA
.endif

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
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif
.if ${PORT_OPTIONS:MNLS}
	(cd ${WRKSRC}/locale && \
		${COPYTREE_SHARE} \* ${PREFIX}/share/locale)
	(cd ${WRKSRC} && \
		${FIND} locale -type f | ${SED} "s|^|share/|g" >> ${TMPPLIST})
.endif

.include <bsd.port.mk>
