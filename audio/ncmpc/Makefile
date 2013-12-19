# Created by: Mark Reidel <ports@mark.reidel.info>
# $FreeBSD$

PORTNAME=	ncmpc
PORTVERSION=	0.20
CATEGORIES=	audio
MASTER_SITES=	SF/musicpd/${PORTNAME}/${PORTVERSION}

MAINTAINER=	henrik@affekt.org
COMMENT=	Ncurses client for the musicpd

LIB_DEPENDS=	libmpdclient.so:${PORTSDIR}/audio/libmpdclient

GNU_CONFIGURE=	yes
USE_GNOME=	glib20
NO_STAGE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS LYRICS
OPTIONS_DEFAULT=	LYRICS
LYRICS_DESC=	Compile with lyrics screen

.include <bsd.port.options.mk>

USES=		iconv pkgconfig
PLIST_FILES=	bin/ncmpc \
		%%EXAMPLESDIR%%/config \
		%%EXAMPLESDIR%%/keys \
		%%EXAMPLESDIR%%/ncmpc.lirc
PLIST_DIRS=%%EXAMPLESDIR%%

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
LANGUAGES=cs da de eo es fi fr gl he hu it ko nb nl pl pt_BR ru sk sv uk zh_CN
.for language in ${LANGUAGES}
PLIST_FILES+=share/locale/${language}/LC_MESSAGES/ncmpc.mo
.endfor
.else
CONFIGURE_ARGS+=--disable-nls
.endif

.if ${PORT_OPTIONS:MLYRICS}
CONFIGURE_ARGS+=--enable-lyrics-screen
PLIST_FILES+=	lib/ncmpc/lyrics/10-hd.sh \
		lib/ncmpc/lyrics/15-leoslyrics.sh \
		lib/ncmpc/lyrics/20-lyricwiki.rb \
		lib/ncmpc/lyrics/30-leoslyrics.py
PLIST_DIRS+=	lib/ncmpc/lyrics \
		lib/ncmpc
.else
CONFIGURE_ARGS+=--disable-lyrics-screen
.endif

MAN1=		ncmpc.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|' \
	    ${WRKSRC}/lyrics/30-leoslyrics.py

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ncmpc ${PREFIX}/bin/
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/config.sample ${EXAMPLESDIR}/config
	${INSTALL_DATA} ${WRKSRC}/doc/keys.sample ${EXAMPLESDIR}/keys
	${INSTALL_DATA} ${WRKSRC}/doc/ncmpc.lirc ${EXAMPLESDIR}/
	${INSTALL_MAN} ${WRKSRC}/doc/ncmpc.1 ${MAN1PREFIX}/man/man1/
.if ${PORT_OPTIONS:MNLS}
.for language in ${LANGUAGES}
	${MKDIR} ${LOCALBASE}/share/locale/${language}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${language}.gmo ${PREFIX}/share/locale/${language}/LC_MESSAGES/ncmpc.mo
.endfor
.endif
.if ${PORT_OPTIONS:MLYRICS}
	${MKDIR} ${PREFIX}/lib/ncmpc/lyrics
	${INSTALL_SCRIPT} ${WRKSRC}/lyrics/10-hd.sh ${PREFIX}/lib/ncmpc/lyrics/10-hd.sh
	${INSTALL_SCRIPT} ${WRKSRC}/lyrics/15-leoslyrics.sh ${PREFIX}/lib/ncmpc/lyrics/15-leoslyrics.sh
	${INSTALL_SCRIPT} ${WRKSRC}/lyrics/20-lyricwiki.rb ${PREFIX}/lib/ncmpc/lyrics/20-lyricwiki.rb
	${INSTALL_SCRIPT} ${WRKSRC}/lyrics/30-leoslyrics.py ${PREFIX}/lib/ncmpc/lyrics/30-leoslyrics.py
.endif

.include <bsd.port.mk>
