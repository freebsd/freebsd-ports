# New ports collection makefile for:	jack-keyboard
# Date created:		2007-01-23
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	jack-keyboard
DISTVERSION=	2.3
CATEGORIES=	audio
MASTER_SITES=	http://pin.if.uz.zgora.pl/~trasz/jack-keyboard/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trasz

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Virtual keyboard for JACK MIDI

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack \
		lash.2:${PORTSDIR}/audio/lash

PLIST_FILES=	bin/jack-keyboard share/icons/hicolor/48x48/apps/jack-keyboard.png
PORTDOCS=	README NEWS
MAN1=		jack-keyboard.1

USE_GNOME=	gtk20
INSTALLS_ICONS=	yes
DESKTOP_ENTRIES="JACK Keyboard" "Virtual keyboard for JACK MIDI" "jack-keyboard.png" \
		"jack-keyboard" "Application;Audio;Midi;" false
USE_GCC=	3.4+

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/jack-keyboard ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/jack-keyboard.1 ${MAN1PREFIX}/man/man1/
		${INSTALL_DATA} ${WRKSRC}/jack-keyboard.png ${PREFIX}/share/icons/hicolor/48x48/apps
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}/
		${INSTALL_MAN} ${WRKSRC}/NEWS ${DOCSDIR}/
.endif

.include <bsd.port.mk>
