# New ports collection makefile for:	mp3burn
# Date created:				17th December 2003
# Whom:					Vincent Tantardini <vinc@FreeBSD-fr.org>
#
# $FreeBSD$

PORTNAME=	mp3burn
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Command line tool for making audio CDs from mp3s

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123 \
		ogg123:${PORTSDIR}/audio/vorbis-tools \
		${SITE_PERL}/MP3/Info.pm:${PORTSDIR}/audio/p5-MP3-Info \
		${SITE_PERL}/${PERL_ARCH}/Ogg/Vorbis/Header.pm:${PORTSDIR}/audio/p5-Ogg-Vorbis-Header \
		${SITE_PERL}/String/ShellQuote.pm:${PORTSDIR}/textproc/p5-String-ShellQuote

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_PERL5=	yes
USE_CDRTOOLS=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/mp3burn

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|g' \
		-e 's|/bin/uname|/usr/bin/uname|g' \
		-e 's|x86_64|amd64|g' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp3burn ${PREFIX}/bin

.include <bsd.port.mk>
