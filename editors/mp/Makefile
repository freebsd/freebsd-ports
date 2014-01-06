# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	mp
PORTVERSION=	5.2.7
CATEGORIES=	editors
MASTER_SITES=	http://triptico.com/download/mp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programming text editor

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	NLS PCRE DOCS
OPTIONS_RADIO=	GUI
OPTIONS_RADIO_GUI=	GTK3 GTK2 QT4
OPTIONS_DEFAULT=	PCRE
OPTIONS_SUB=	yes

USES=		iconv ncurses
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	config.sh
CONFIGURE_ARGS=	--prefix=${PREFIX} --without-win32 --without-kde4

DATADIR=	${PREFIX}/share/mp-5

NLS_USES=	gettext
NLS_CONFIGURE_WITH=	gettext

PCRE_LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre
PCRE_CONFIGURE_WITH=	pcre

QT4_USE=		QT4=corelib,gui,moc_build
QT4_CONFIGURE_ENV=	CPP="${CXX}" CCLINK="${CXX}"
QT4_CONFIGURE_WITH=	qt4

.include <bsd.port.options.mk>

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
QT_NONSTANDARD=	yes
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|<ncursesw/|<| ; \
		 s|-I/usr/local/include|| ; \
		 s|-L/usr/local/lib|| ; \
		 s|-lX11|| ; \
		 /gtk+/s|3.0|${CONFOPT_GTK}.0| ; \
		 /OK/s|3.0|${CONFOPT_GTK}.0| ; \
		 /CONFOPT_GTK/s|3|${CONFOPT_GTK}|' ${WRKSRC}/config.sh
	@${REINPLACE_CMD} -e \
		's|<ncursesw/|<|g' ${WRKSRC}/mpv_curses.c
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}| ; \
		 s|%%ICONV_PREFIX%%|${ICONV_PREFIX}| ; \
		 s|%%ICONV_LIB%%|${ICONV_LIB}|g' ${WRKSRC}/mpdm/config.sh
.for i in mpdm/mpdm.h mpdm/mpdm_s.c mpsl/mpsl_d.c
	@${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g' ${WRKSRC}/${i}
.endfor

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} mp-5 ${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/mpsl && ${INSTALL_PROGRAM} mpsl ${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} mp-5.1 ${STAGEDIR}${MANPREFIX}/man/man1)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} mp_*.mpsl ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DATADIR}/lang
	(cd ${WRKSRC}/lang && ${INSTALL_DATA} *.mpsl ${STAGEDIR}${DATADIR}/lang)
.if ${PORT_OPTIONS:MNLS}
.for lang in de es it nl ru sv
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES
	(cd ${WRKSRC}/po && ${INSTALL_DATA} ${lang}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/minimum-profit.mo)
.endfor
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS README RELEASE_NOTES mp_templates.sample doc/*.*
	(cd ${WRKSRC} && ${INSTALL_DATA} ${doc} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.post.mk>
