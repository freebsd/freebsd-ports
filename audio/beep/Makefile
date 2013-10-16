# Created by: Tyler Spivey
# $FreeBSD$

PORTNAME=	beep
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Beeps a certain duration and pitch out of the PC Speaker

WRKSRC=		${WRKDIR}/${PORTNAME}

ONLY_FOR_ARCHS=	i386 amd64 pc98

PLIST_FILES=	bin/beep man/man1/beep.1.gz

post-patch:
	${REINPLACE_CMD} 's|machine/speaker\.h|dev/speaker/speaker.h|' \
		${WRKSRC}/beep.c

.include <bsd.port.mk>
