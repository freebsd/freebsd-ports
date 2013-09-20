# Created by: Vincent Tantardini <vinc@FreeBSD-fr.org>
# $FreeBSD$

PORTNAME=	mp3burn
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Command line tool to burn audio CDs from MP3, Ogg, Vorbis, FLAC files

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123 \
		ogg123:${PORTSDIR}/audio/vorbis-tools \
		p5-MP3-Info>=0:${PORTSDIR}/audio/p5-MP3-Info \
		p5-Ogg-Vorbis-Header>=0:${PORTSDIR}/audio/p5-Ogg-Vorbis-Header \
		p5-String-ShellQuote>=0:${PORTSDIR}/textproc/p5-String-ShellQuote \
		cdda2wav:${PORTSDIR}/sysutils/cdrtools

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
NO_STAGE=	yes
USES=		perl5
NO_BUILD=	yes

PLIST_FILES=	bin/mp3burn

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|g' \
		-e 's|/bin/uname|/usr/bin/uname|g' \
		-e 's|x86_64|amd64|g' \
		-e 's|" -pad -audio"|" -tao -pad -audio"|' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp3burn ${PREFIX}/bin

.include <bsd.port.mk>
