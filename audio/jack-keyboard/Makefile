# New ports collection makefile for:	jack-keyboard
# Date created:		2007-01-23
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	jack-keyboard
PORTVERSION=	1.6
CATEGORIES=	audio
MASTER_SITES=	http://pin.if.uz.zgora.pl/~trasz/jack-keyboard/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	trasz@freebsd.org
COMMENT=	Virtual keyboard for JACK MIDI

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack

PLIST_FILES=	bin/jack-keyboard
PORTDOCS=	README NEWS
MAN1=		jack-keyboard.1

USE_GNOME=	gtk20
USE_GCC=	3.4+

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/jack-keyboard ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}/
		${INSTALL_MAN} ${WRKSRC}/NEWS ${DOCSDIR}/
		${INSTALL_MAN} ${WRKSRC}/jack-keyboard.1 ${MAN1PREFIX}/man/man1/
.endif

.include <bsd.port.mk>
