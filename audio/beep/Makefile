# Created by: Tyler Spivey
# $FreeBSD$

PORTNAME=	beep
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	LOCAL/garga/${PORTNAME}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Beeps a certain duration and pitch out of the PC Speaker

LICENSE=	BSD4CLAUSE

WRKSRC=		${WRKDIR}/${PORTNAME}

ONLY_FOR_ARCHS=	i386 amd64 pc98

PLIST_FILES=	bin/beep man/man1/beep.1.gz

post-patch:
	@${REINPLACE_CMD} 's|machine/speaker\.h|dev/speaker/speaker.h|' \
		${WRKSRC}/beep.c

.include <bsd.port.mk>
