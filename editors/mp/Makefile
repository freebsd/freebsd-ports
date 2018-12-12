# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	mp
DISTVERSION=	5.2.13
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://triptico.com/download/mp/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Programming text editor

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake iconv

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	config.sh
CONFIGURE_ARGS=	--prefix=${PREFIX} --docdir=${DOCSDIR} \
		--without-win32 --without-kde4
CONFIGURE_ENV=	LOCALBASE="${LOCALBASE}" \
		ICONV_LIB="${ICONV_LIB}" \
		ICONV_PREFIX="${ICONV_PREFIX}" \
		NCURSESINC="${NCURSESINC}" \
		NCURSESLIB="${NCURSESLIB}"
LDFLAGS+=	-Wl,--as-needed

DATADIR=	${PREFIX}/share/mp-5

OPTIONS_DEFINE=		DOCS NLS PCRE
OPTIONS_SINGLE=		GUI
OPTIONS_SINGLE_GUI=	ANSI GTK2 GTK3 NCURSES QT4 QT5
OPTIONS_DEFAULT=	NCURSES PCRE
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_WITH=	gettext

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_WITH=	pcre

ANSI_DESC=		ANSI terminal support
ANSI_CONFIGURE_WITH=	ansi

GTK2_USE=		gnome=cairo,gdkpixbuf2,gtk20
GTK2_CONFIGURE_ON=	--with-gtk=2

GTK3_USE=		gnome=cairo,gdkpixbuf2,gtk30
GTK3_CONFIGURE_ON=	--with-gtk=3

NCURSES_USES=		ncurses
NCURSES_CONFIGURE_WITH=	curses
NCURSES_CFLAGS=		-I${NCURSESBASE}/include

QT4_USES=		qmake:no_env qt:4
QT4_USE=		qt=corelib,gui,moc_build \
			xorg=x11
QT4_CONFIGURE_WITH=	qt4

QT5_USES=		compiler:c++11-lang qmake:no_env qt:5
QT5_USE=		cxxstd=-std=c++11 \
			gl=gl \
			qt=buildtools_build,core,gui,widgets
QT5_CONFIGURE_WITH=	qt5

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK*} || ${PORT_OPTIONS:MQT*}
USES+=		pkgconfig
PLIST_SUB+=	GUI=""
.else
PLIST_SUB+=	GUI="@comment "
.endif

.if ${PORT_OPTIONS:MGTK*}
DESKTOP_ENTRIES="Minimum Profit" "" "mp" "mp-5" "Utility;TextEditor;GTK;" ""
.else
CONFIGURE_ARGS+=	--without-gtk
.endif

.if ${PORT_OPTIONS:MQT*}
DESKTOP_ENTRIES="Minimum Profit" "" "mp" "mp-5" "Utility;TextEditor;Qt;" ""
CONFIGURE_ARGS+=--with-moc=${MOC}
CONFIGURE_ENV+=	CCLINK="${CXX}"
.endif

.if ${PORT_OPTIONS:MQT4}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

post-patch:
.for i in mpdm/mpdm.h mpsl/mpsl_d.c
	@${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g' ${WRKSRC}/${i}
.endfor

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
	${INSTALL_PROGRAM} ${WRKSRC}/mpsl/mpsl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mp-5.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mp_*.mpsl ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/lang
	${INSTALL_DATA} ${WRKSRC}/lang/*.mpsl ${STAGEDIR}${DATADIR}/lang
.if ${PORT_OPTIONS:MGTK*} || ${PORT_OPTIONS:MQT*}
	${INSTALL_DATA} ${WRKSRC}/mp.png ${STAGEDIR}${PREFIX}/share/pixmaps
.endif

do-install-NLS-on:
.for lang in de es it nl ru sv
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/minimum-profit.mo
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS README RELEASE_NOTES mp_templates.sample doc/*.*
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
