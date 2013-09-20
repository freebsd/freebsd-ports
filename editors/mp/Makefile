# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	mp
PORTVERSION=	5.2.6
CATEGORIES=	editors
MASTER_SITES=	http://triptico.com/download/mp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programming text editor

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	NLS PCRE DOCS
OPTIONS_RADIO=	GUI
OPTIONS_RADIO_GUI=	GTK3 GTK2 QT4
OPTIONS_DEFAULT=	PCRE

USES=		iconv ncurses
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	config.sh
CONFIGURE_ARGS=	--prefix=${PREFIX} --without-win32 --without-kde4

MAN1=		mp-5.1

DATADIR=	${PREFIX}/share/mp-5

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--without-gettext
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MGTK3}
USE_GNOME+=	gtk30
CONFOPT_GTK=	3
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
CONFOPT_GTK=	2
.endif

.if empty(PORT_OPTIONS:MGTK3) && empty(PORT_OPTIONS:MGTK2)
CONFIGURE_ARGS+=	--without-gtk
CONFOPT_GTK=	0
.endif

.if ${PORT_OPTIONS:MQT4}
USE_QT4=	corelib gui moc_build
QT_NONSTANDARD=	yes
CONFIGURE_ENV+=	CPP="${CXX}" CCLINK="${CXX}"
.else
CONFIGURE_ARGS+=	--without-qt4
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--with-pcre
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|<ncursesw/|<| ; \
		 s|-I/usr/local/include|| ; \
		 s|-L/usr/local/lib|| ; \
		 s|-lX11|| ; \
		 /gtk+/s|3.0|${CONFOPT_GTK}.0| ; \
		 /OK/s|3.0|${CONFOPT_GTK}.0| ; \
		 /CONFOPT_GTK/s|3|${CONFOPT_GTK}|' ${WRKSRC}/config.sh
	@${REINPLACE_CMD} -e 's|<ncursesw/|<|g' ${WRKSRC}/mpv_curses.c
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/mpdm/config.sh
.for i in mpdm/mpdm.h mpdm/mpdm_s.c mpsl/mpsl_d.c
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g' ${WRKSRC}/${i}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp-5 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mpsl/mpsl2 ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mp-5.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mp_*.mpsl ${DATADIR}
	@${MKDIR} ${DATADIR}/lang
	${INSTALL_DATA} ${WRKSRC}/lang/*.mpsl ${DATADIR}/lang
.if ${PORT_OPTIONS:MNLS}
.for lang in de es it nl ru sv
	@${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/minimum-profit.mo
.endfor
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for doc in AUTHORS README RELEASE_NOTES mp_templates.sample doc/*.*
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
