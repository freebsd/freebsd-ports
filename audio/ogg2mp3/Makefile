# New ports collection makefile for:	ogg2mp3
# Date created:			26 Jun 2005
# Whom:				Aleksander Fafula <alex@bsdguru.org>
#
# $FreeBSD$

PORTNAME=	ogg2mp3
PORTVERSION=	0.5
CATEGORIES=	audio
MASTER_SITES=	http://amor.cms.hu-berlin.de/~h0444y2j/pub/

MAINTAINER=	alex@bsdguru.org
COMMENT=	Perl script that converts Ogg Vorbis files to MP3 format

RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame \
		${SITE_PERL}/String/ShellQuote.pm:${PORTSDIR}/textproc/p5-String-ShellQuote \
		ogginfo:${PORTSDIR}/audio/vorbis-tools

NO_BUILD=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes

PLIST_FILES=	bin/ogg2mp3

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin|/usr/local/bin|g' \
		${WRKSRC}/ogg2mp3

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ogg2mp3 ${PREFIX}/bin

.include <bsd.port.mk>
