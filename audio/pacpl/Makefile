# New ports collection makefile for:	pacpl
# Date created:		21 July 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pacpl
PORTVERSION=	3.2.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	pac-${PORTVERSION}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Perl Audio Converter

RUN_DEPENDS=	${SITE_PERL}/MP3/Tag.pm:${PORTSDIR}/audio/p5-MP3-Tag \
		${SITE_PERL}/MP4/Info.pm:${PORTSDIR}/multimedia/p5-MP4-Info \
		${SITE_PERL}/Audio/WMA.pm:${PORTSDIR}/audio/p5-Audio-WMA \
		${SITE_PERL}/${PERL_ARCH}/Ogg/Vorbis/Header.pm:${PORTSDIR}/audio/p5-Ogg-Vorbis-Header \
		${SITE_PERL}/${PERL_ARCH}/Audio/FLAC/Header.pm:${PORTSDIR}/audio/p5-Audio-FLAC-Header \
		${SITE_PERL}/Audio/Musepack.pm:${PORTSDIR}/audio/p5-Audio-Musepack \
		lame:${PORTSDIR}/audio/lame \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		flac:${PORTSDIR}/audio/flac \
		mac:${PORTSDIR}/audio/mac \
		shorten:${PORTSDIR}/audio/shorten \
		faac:${PORTSDIR}/audio/faac \
		faad:${PORTSDIR}/audio/faad \
		mppenc:${PORTSDIR}/audio/musepack \
		wavpack:${PORTSDIR}/audio/wavpack \
		ttaenc:${PORTSDIR}/audio/tta \
		kexis:${PORTSDIR}/audio/kexis \
		sox:${PORTSDIR}/audio/sox \
		ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
		bonk:${PORTSDIR}/audio/bonk \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		cdparanoia:${PORTSDIR}/audio/cdparanoia \
		mpg123:${PORTSDIR}/audio/mpg123 \
		laudio:${PORTSDIR}/audio/laudio \
		ofr:${PORTSDIR}/audio/optimfrog \
		lpac:${PORTSDIR}/audio/lpac

ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes
FR_FILES=	help long_help rip_help tag_help video_help
PLIST_FILES=	bin/pacpl etc/pacpl/pacpl.conf ${FR_FILES:S,^,etc/pacpl/lang/FR/,:S,$,.FR,}
PLIST_DIRS=	etc/pacpl/lang/FR etc/pacpl/lang etc/pacpl
MAN1=		pacpl.1

post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/man/pac.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's#/etc#${PREFIX}/etc#' ${WRKSRC}/pac
	@${REINPLACE_CMD} -Ee 's#([^a-zA-Z]|^)pac([^a-zA-Z]|$$)#\1pacpl\2#g' \
			  -Ee 's#([^a-zA-Z]|^)PAC([^a-zA-Z]|$$)#\1PACPL\2#g' \
		${WRKSRC}/pac ${WRKSRC}/man/pac.1
	@${REINPLACE_CMD} -e 's#%%LOCALBASE%%#${LOCALBASE}#' ${WRKSRC}/pac.conf

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/pac ${PREFIX}/bin/pacpl
	@${INSTALL} -d ${PREFIX}/etc/pacpl/lang/FR
	@${INSTALL_DATA} ${WRKSRC}/pac.conf ${PREFIX}/etc/pacpl/pacpl.conf
	@${INSTALL_DATA} ${FR_FILES:S,^,${WRKSRC}/lang/FR/,:S,$,.FR,} ${PREFIX}/etc/pacpl/lang/FR/
	@${INSTALL_MAN} ${WRKSRC}/man/pac.1 ${MAN1PREFIX}/man/man1/pacpl.1

.include <bsd.port.mk>
