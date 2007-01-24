# New ports collection makefile for:	jack-keyboard
# Date created:		2007-01-23
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	jack-keyboard
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	http://pin.if.uz.zgora.pl/~trasz/jack-keyboard/

MAINTAINER=	trasz@pin.if.uz.zgora.pl
COMMENT=	Virtual keyboard for JACK MIDI

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack

PLIST_FILES=	bin/jack-keyboard "%%DOCSDIR%%/README"
PLIST_DIRS=	"%%DOCSDIR%%"

USE_GNOME=	gtk20
USE_GCC=	3.4+

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/jack-keyboard ${PREFIX}/bin
		${MKDIR} ${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}/

.include <bsd.port.mk>
