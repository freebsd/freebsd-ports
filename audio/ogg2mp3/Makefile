# Created by: Aleksander Fafula <alex@bsdguru.org>
# $FreeBSD$

PORTNAME=	ogg2mp3
PORTVERSION=	0.6.1
PORTREVISION?=	2
CATEGORIES=	audio
MASTER_SITES=	http://atarininja.org/distfiles/

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Perl script that converts Ogg Vorbis files to MP3 format

LICENSE=	GPLv2

RUN_DEPENDS=	lame:audio/lame \
		p5-String-ShellQuote>=0:textproc/p5-String-ShellQuote \
		ogginfo:audio/vorbis-tools

NO_BUILD=	yes
USES=		perl5 tar:bzip2

PLIST_FILES=	bin/ogg2mp3

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|" ${WRKSRC}/ogg2mp3

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ogg2mp3 ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
