# Created by: Mark Reidel <ports@mark.reidel.info>
# $FreeBSD$

PORTNAME=	ncmpc
PORTVERSION=	0.24
CATEGORIES=	audio
MASTER_SITES=	http://www.musicpd.org/download/ncmpc/0/

MAINTAINER=	henrik@affekt.org
COMMENT=	Ncurses client for the musicpd

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient

GNU_CONFIGURE=	yes
USE_GNOME=	glib20
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS LYRICS
OPTIONS_DEFAULT=	LYRICS
LYRICS_DESC=	Compile with lyrics screen

USES=		iconv pkgconfig
PLIST_FILES=	bin/ncmpc \
		man/man1/ncmpc.1.gz \
		%%EXAMPLESDIR%%/config \
		%%EXAMPLESDIR%%/keys \
		%%EXAMPLESDIR%%/ncmpc.lirc

NLS_USES=		gettext

LANGUAGES=cs da de eo es fi fr gl he hu it ko nb nl pl pt_BR ru sk sv uk zh_CN
.for language in ${LANGUAGES}
NLS_PLIST_FILES+=share/locale/${language}/LC_MESSAGES/ncmpc.mo
.endfor
NLS_CONFIGURE_OFF=--disable-nls

LYRICS_CONFIGURE_ENABLE=	lyrics-screen
LYRICS_PLIST_FILES=	lib/ncmpc/lyrics/10-hd.sh \
		lib/ncmpc/lyrics/20-lyricwiki.rb

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ncmpc ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/config.sample ${STAGEDIR}${EXAMPLESDIR}/config
	${INSTALL_DATA} ${WRKSRC}/doc/keys.sample ${STAGEDIR}${EXAMPLESDIR}/keys
	${INSTALL_DATA} ${WRKSRC}/doc/ncmpc.lirc ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/ncmpc.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
do-install-NLS-on:
.for language in ${LANGUAGES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${language}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${language}.gmo \
		${STAGEDIR}${PREFIX}/share/locale/${language}/LC_MESSAGES/ncmpc.mo
.endfor
do-install-LYRICS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ncmpc/lyrics
	(cd ${WRKSRC}/lyrics && ${INSTALL_SCRIPT} \
		10-hd.sh 20-lyricwiki.rb \
		${STAGEDIR}${PREFIX}/lib/ncmpc/lyrics)

.include <bsd.port.mk>
