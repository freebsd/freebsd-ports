PORTNAME=	cwirc
PORTVERSION=	2.0.0
PORTREVISION=	7
CATEGORIES=	irc comms hamradio
MASTER_SITES=	http://myspace.voo.be/pcoupard/cwirc/download/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	X-Chat Morse plugin

LICENSE=	GPLv2

BUILD_DEPENDS=	hexchat:irc/hexchat
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext-runtime gnome pkgconfig
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 pango

post-patch:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%STAGEDIR%%|${STAGEDIR}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|xchat|hexchat|g' \
		-e 's|XCHAT|HEXCHAT|g' ${WRKSRC}/plugin.c
	@${RM} -r ${WRKSRC}/xchat

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in COPYING LISEZMOI README RELEASE_NOTES
	${INSTALL_DATA}  ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}/schematics
.for f in cw_oscillator.jpg rs232_key_connection.jpg
	${INSTALL_DATA} ${WRKSRC}/schematics/$f ${STAGEDIR}${DOCSDIR}/schematics
.endfor

.include <bsd.port.mk>
