# New ports collection makefile for:	mp3burn
# Date created:				17th December 2003
# Whom:					Vincent Tantardini <vinc@FreeBSD-fr.org>
#
# $FreeBSD$

PORTNAME=	mp3burn
PORTVERSION=	0.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line tool for making audio CDs from mp3s

RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools \
		mpg123:${PORTSDIR}/audio/mpg123 \
		${SITE_PERL}/MPEG/MP3Info.pm:${PORTSDIR}/audio/p5-MP3-Info

USE_PERL5=	yes
NO_BUILD=	yes
USE_REINPLACE=	yes
MAN1=		mp3burn.1
MANCOMPRESSED=	no
PLIST_FILES=	bin/mp3burn

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' ${WRKSRC}/mp3burn

do-install:
	@${CP} ${WRKSRC}/mp3burn ${PREFIX}/bin
	@${CP} ${WRKSRC}/mp3burn.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
