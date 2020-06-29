# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	mp
PORTVERSION=	5.41
CATEGORIES=	editors
MASTER_SITES=	http://triptico.com/download/mp/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Programming text editor

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake iconv

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	config.sh
CONFIGURE_ARGS=	--prefix=${PREFIX} --docdir=${DOCSDIR} \
		--without-win32 --without-kde4 --without-qt4
CONFIGURE_ENV=	LOCALBASE="${LOCALBASE}" \
		ICONV_LIB="${ICONV_LIB}" \
		ICONV_PREFIX="${ICONV_PREFIX}" \
		NCURSESINC="${NCURSESINC}" \
		NCURSESLIB="${NCURSESLIB}"
LDFLAGS+=	-Wl,--as-needed
LLD_UNSAFE=	yes
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		DOCS NLS PCRE
OPTIONS_RADIO=		GUI
OPTIONS_RADIO_GUI=	GTK2 GTK3 QT5
CONSOLE_DESC=		${NCURSES_DESC}
OPTIONS_SINGLE=		CONSOLE
OPTIONS_SINGLE_CONSOLE=	ANSI NCURSES
OPTIONS_DEFAULT=	NCURSES PCRE
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_WITH=	gettext

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_WITH=	pcre

ANSI_DESC=		ANSI terminal support
ANSI_CONFIGURE_WITH=	ansi

GTK2_USES=		gnome pkgconfig
GTK2_USE=		gnome=cairo,gdkpixbuf2,gtk20
GTK2_CONFIGURE_ON=	--with-gtk=2

GTK3_USES=		gnome pkgconfig
GTK3_USE=		gnome=cairo,gdkpixbuf2,gtk30
GTK3_CONFIGURE_ON=	--with-gtk=3

NCURSES_USES=		ncurses
NCURSES_CONFIGURE_WITH=	curses
NCURSES_CFLAGS=		-I${NCURSESBASE}/include

QT5_USES=		compiler:c++11-lang gl pkgconfig qmake:no_env qt:5
QT5_USE=		cxxstd=-std=c++11 \
			gl=gl \
			qt=buildtools_build,core,gui,widgets
QT5_CONFIGURE_ENV=	CCLINK="${CXX}"
QT5_CONFIGURE_ON=	--with-qt5 --with-moc="${MOC}"
QT5_CONFIGURE_OFF=	--without-qt

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK*} || ${PORT_OPTIONS:MQT5}
USES+=		desktop-file-utils
PLIST_SUB+=	GUI=""
.else
PLIST_SUB+=	GUI="@comment "
.endif

.if !${PORT_OPTIONS:MGTK*}
CONFIGURE_ARGS+=	--without-gtk
.endif

do-configure:
	@(for CONFIGURE_WRKSRC in ${WRKSRC}/mpdm ${WRKSRC}/mpsl ${WRKSRC}; \
	  do \
	    cd $${CONFIGURE_WRKSRC} && \
	      ${SETENV} CC="${CC}" CPP="${CXX}" \
	      CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
	      LDFLAGS="${LDFLAGS}" LIBS="${LIBS}" \
	      ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS}; \
	  done;)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp-5 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mp-5.1 ${STAGEDIR}${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MGTK*} || ${PORT_OPTIONS:MQT5}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/minimum-profit.desktop ${STAGEDIR}${PREFIX}/share/applications
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps
	${INSTALL_DATA} ${WRKSRC}/minimum-profit.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps
.endif

do-install-NLS-on:
.for lang in de es it nl ru sv
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/minimum-profit.mo
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS README RELEASE_NOTES mp_templates.sample doc/* mpdm/doc/* mpsl/doc/*
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
