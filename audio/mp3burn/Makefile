# New ports collection makefile for:	mp3burn
# Date created:				17th December 2003
# Whom:					Vincent Tantardini <vinc@FreeBSD-fr.org>
#
# $FreeBSD$

PORTNAME=	mp3burn
PORTVERSION=	0.4.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line tool for making audio CDs from mp3s

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123 \
		ogg123:${PORTSDIR}/audio/vorbis-tools \
		${SITE_PERL}/MPEG/MP3Info.pm:${PORTSDIR}/audio/p5-MP3-Info \
		${SITE_PERL}/${PERL_ARCH}/Ogg/Vorbis/Header.pm:${PORTSDIR}/audio/p5-Ogg-Vorbis-Header \
		cdrecord:${PORTSDIR}/sysutils/cdrtools \
		${SITE_PERL}/String/ShellQuote.pm:${PORTSDIR}/textproc/p5-String-ShellQuote

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_PERL5=	yes
NO_BUILD=	yes

MAN1=		mp3burn.1
PLIST_FILES=	bin/mp3burn

post-patch:
	@${PERL} -pi -e 's|/usr/bin/perl|${PERL}|' ${WRKSRC}/mp3burn

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp3burn ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mp3burn.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
