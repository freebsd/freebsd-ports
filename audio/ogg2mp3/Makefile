# Created by: Aleksander Fafula <alex@bsdguru.org>
# $FreeBSD$

PORTNAME=	ogg2mp3
PORTVERSION=	0.6.1
PORTREVISION?=	2
CATEGORIES=	audio
MASTER_SITES=	http://jamesa.com/projects/ogg2mp3/releases/

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Perl script that converts Ogg Vorbis files to MP3 format

RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame \
		p5-String-ShellQuote>=0:${PORTSDIR}/textproc/p5-String-ShellQuote \
		ogginfo:${PORTSDIR}/audio/vorbis-tools

NO_BUILD=	yes
USE_BZIP2=	yes
NO_STAGE=	yes
USES=		perl5

PLIST_FILES=	bin/ogg2mp3

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|" ${WRKSRC}/ogg2mp3

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ogg2mp3 ${PREFIX}/bin

.include <bsd.port.mk>
