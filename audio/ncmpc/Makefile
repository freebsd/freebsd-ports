# New ports collection makefile for:	ncmpc
# Date created:		Apr 14 2004
# Whom:			Mark Reidel <ports@mark.reidel.info>
#
# $FreeBSD$
#

PORTNAME=	ncmpc
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/musicpd/${PORTNAME}/${PORTVERSION}

MAINTAINER=	hrkfdn@gmail.com
COMMENT=	Ncurses client for the musicpd

LIB_DEPENDS=	mpdclient:${PORTSDIR}/audio/libmpdclient

GNU_CONFIGURE=	yes
USE_GNOME=	glib20
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	NLS "Native language support" on \
		LYRICS "Compile with lyrics screen" on

.include <bsd.port.pre.mk>

USE_ICONV=	yes
PLIST_FILES=	bin/ncmpc \
		%%EXAMPLESDIR%%/config \
		%%EXAMPLESDIR%%/keys \
		%%EXAMPLESDIR%%/ncmpc.lirc
PLIST_DIRS=%%EXAMPLESDIR%%

.ifdef(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
.else
USE_GETTEXT=	yes
LANGUAGES=cs da de eo es fr gl he hu ko nb nl ru sk sv uk zh_CN
.for language in ${LANGUAGES}
PLIST_FILES+=share/locale/${language}/LC_MESSAGES/ncmpc.mo
.endfor

.endif

.ifdef(WITH_LYRICS)
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
.if !defined(WITHOUT_NLS)
.for language in ${LANGUAGES}
	${MKDIR} ${LOCALBASE}/share/locale/${language}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${language}.gmo ${PREFIX}/share/locale/${language}/LC_MESSAGES/ncmpc.mo
.endfor
.endif
.if !defined(WITHOUT_LYRICS)
	${MKDIR} ${PREFIX}/lib/ncmpc/lyrics
	${INSTALL_SCRIPT} ${WRKSRC}/lyrics/10-hd.sh ${PREFIX}/lib/ncmpc/lyrics/10-hd.sh
	${INSTALL_SCRIPT} ${WRKSRC}/lyrics/15-leoslyrics.sh ${PREFIX}/lib/ncmpc/lyrics/15-leoslyrics.sh
	${INSTALL_SCRIPT} ${WRKSRC}/lyrics/20-lyricwiki.rb ${PREFIX}/lib/ncmpc/lyrics/20-lyricwiki.rb
	${INSTALL_SCRIPT} ${WRKSRC}/lyrics/30-leoslyrics.py ${PREFIX}/lib/ncmpc/lyrics/30-leoslyrics.py
.endif

.include <bsd.port.post.mk>
