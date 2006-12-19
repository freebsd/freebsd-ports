# New ports collection makefile for:	pacpl
# Date created:		21 July 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pacpl
PORTVERSION=	3.2.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SFE

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
PACPL_LNG_FILES=	help long_help rip_help tag_help video_help
PACPL_LNGS=	FR PT
AMAROK_SCR=	README transcoding_pacx.pl
AMAROK_SCR_DIR=	share/apps/amarok/scripts/transcoding_pacx
KONQ_MIME=	ape bonk kxs la lpac ofr ofs shn tta wavpack
KONQ_SVCM=	${PORTNAME}
KONQ_MIME_DIR=	share/mimelnk/audio
KONQ_SVCM_DIR=	share/apps/konqueror/servicemenus
PLIST_FILES=	bin/pacpl etc/pacpl/pacpl.conf \
		${PACPL_LNG_FILES:S,^,etc/pacpl/lang/FR/,:S,$,.FR,} \
		${PACPL_LNG_FILES:S,^,etc/pacpl/lang/PT/,:S,$,.PT,} \
		${AMAROK_SCR:S|^|${AMAROK_SCR_DIR}/|} \
		${AMAROK_SCR_DIR}/transcoding_pacx.spec \
		${KONQ_MIME:S|^|${KONQ_MIME_DIR}/x-|:S|$|.desktop|} \
		${KONQ_SVCM:S|^|${KONQ_SVCM_DIR}/|:S|$|.desktop|}
PLIST_DIRS=	etc/pacpl/lang/FR etc/pacpl/lang/PT etc/pacpl/lang etc/pacpl
MAN1=		pacpl.1

post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/man/pacpl.1.gz
	@cd ${WRKSRC}/kde/amarok && ${TAR} xf pacx.amarokscript.tar.gz
	@cd ${WRKSRC}/kde/amarok/pacx.amarokscript && ${MV} pacx.pl transcoding_pacx.pl

post-patch:
	@${REINPLACE_CMD} -e 's#/etc#${PREFIX}/etc#' ${WRKSRC}/pacpl
	@${REINPLACE_CMD} -e 's#%%LOCALBASE%%#${LOCALBASE}#' ${WRKSRC}/pacpl.conf

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/pacpl ${PREFIX}/bin/
	@${INSTALL} -d ${PACPL_LNGS:S,^,${PREFIX}/etc/pacpl/lang/,}
	@${INSTALL_DATA} ${PACPL_LNG_FILES:S,^,${WRKSRC}/lang/FR/,:S,$,.FR,} ${PREFIX}/etc/pacpl/lang/FR/
	@${INSTALL_DATA} ${PACPL_LNG_FILES:S,^,${WRKSRC}/lang/PT/,:S,$,.PT,} ${PREFIX}/etc/pacpl/lang/PT/
	@${INSTALL_DATA} ${WRKSRC}/pacpl.conf ${PREFIX}/etc/pacpl/
	@${INSTALL_MAN} ${WRKSRC}/man/pacpl.1 ${MAN1PREFIX}/man/man1/
	@${INSTALL} -d ${PREFIX}/${AMAROK_SCR_DIR}/
	@${INSTALL} -d ${PREFIX}/${KONQ_MIME_DIR}/
	@${INSTALL} -d ${PREFIX}/${KONQ_SVCM_DIR}/
	@${INSTALL_DATA} ${AMAROK_SCR:S|^|${WRKSRC}/kde/amarok/pacx.amarokscript/|} \
		${PREFIX}/${AMAROK_SCR_DIR}/
	@${INSTALL_DATA} ${KONQ_MIME:S|^|${WRKSRC}/kde/konqueror/mimes/x-|:S|$|.desktop|} \
		${PREFIX}/${KONQ_MIME_DIR}/
	@${INSTALL_DATA} ${KONQ_SVCM:S|^|${WRKSRC}/kde/konqueror/|:S|$|.desktop|} \
		${PREFIX}/${KONQ_SVCM_DIR}/
	@${CHMOD} a+x ${PREFIX}/${AMAROK_SCR_DIR}/*pl
	@${ECHO_CMD} "name = Pacx" > ${PREFIX}/${AMAROK_SCR_DIR}/transcoding_pacx.spec
	@${ECHO_CMD} "type = transcoding" >> ${PREFIX}/${AMAROK_SCR_DIR}/transcoding_pacx.spec

.include <bsd.port.mk>
