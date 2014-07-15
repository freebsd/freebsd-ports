# Created by: Mark Reidel <ports@mark.reidel.info>
# $FreeBSD$

PORTNAME=	ncmpc
PORTVERSION=	0.23
CATEGORIES=	audio
MASTER_SITES=	http://www.musicpd.org/download/ncmpc/0/

MAINTAINER=	henrik@affekt.org
COMMENT=	Ncurses client for the musicpd

LIB_DEPENDS=	libmpdclient.so:${PORTSDIR}/audio/libmpdclient

GNU_CONFIGURE=	yes
USE_GNOME=	glib20
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS LYRICS
OPTIONS_DEFAULT=	LYRICS
LYRICS_DESC=	Compile with lyrics screen

.include <bsd.port.options.mk>

USES=		iconv pkgconfig
PLIST_FILES=	bin/ncmpc \
		man/man1/ncmpc.1.gz \
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
		lib/ncmpc/lyrics/20-lyricwiki.rb
PLIST_DIRS+=	lib/ncmpc/lyrics \
		lib/ncmpc
.else
CONFIGURE_ARGS+=--disable-lyrics-screen
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ncmpc ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/config.sample ${STAGEDIR}${EXAMPLESDIR}/config
	${INSTALL_DATA} ${WRKSRC}/doc/keys.sample ${STAGEDIR}${EXAMPLESDIR}/keys
	${INSTALL_DATA} ${WRKSRC}/doc/ncmpc.lirc ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/ncmpc.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MNLS}
.for language in ${LANGUAGES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${language}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${language}.gmo \
		${STAGEDIR}${PREFIX}/share/locale/${language}/LC_MESSAGES/ncmpc.mo
.endfor
.endif
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ncmpc/lyrics
	(cd ${WRKSRC}/lyrics && ${INSTALL_SCRIPT} \
		10-hd.sh 20-lyricwiki.rb \
		${STAGEDIR}${PREFIX}/lib/ncmpc/lyrics)

.include <bsd.port.mk>
