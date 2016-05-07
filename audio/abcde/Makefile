# Created by: Munish Chopra <mchopra@engmail.uwaterloo.ca>
# $FreeBSD$

PORTNAME=	abcde
PORTVERSION=	2.7.2
CATEGORIES=	audio
MASTER_SITES=	http://abcde.einval.com/download/

MAINTAINER=	ports@toco-domains.de
COMMENT=	Front-end shell script to encode CDs in flac/mp3/ogg/speex format

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual

RUN_DEPENDS=	cd-discid:audio/cd-discid \
		cdparanoia:audio/cdparanoia \
		lame:audio/lame \
		${PYTHON_PKGNAMEPREFIX}eyed3>=0.7:audio/py-eyed3 \
		oggenc:audio/vorbis-tools \
		bash:shells/bash

NO_ARCH=	yes
NO_BUILD=	yes

USES=		python:run shebangfix
SHEBANG_FILES=	abcde cddb-tool

SUB_FILES=	pkg-message

PLIST_FILES=	bin/abcde bin/cddb-tool etc/abcde.conf.sample \
		man/man1/abcde.1.gz man/man1/cddb-tool.1.gz

OPTIONS_GROUP=		CODEC RIPPER
OPTIONS_GROUP_CODEC=	AAC FLAC MPP OPUS SPEEX
OPTIONS_GROUP_RIPPER=	CDDA2WAV DAGRAB
OPTIONS_DEFINE=		NORMALIZE REPLAYGAIN

AAC_RUN_DEPENDS=	faac:audio/faac
CDDA2WAV_RUN_DEPENDS=	cdda2wav:sysutils/cdrtools
DAGRAB_RUN_DEPENDS=	dagrab:audio/dagrab
FLAC_RUN_DEPENDS=	flac:audio/flac
MPP_RUN_DEPENDS=	mpcenc:audio/musepack
NORMALIZE_DESC=		Enable normalize support
NORMALIZE_RUN_DEPENDS=	normalize:audio/normalize
OPUS_RUN_DEPENDS=	opusenc:audio/opus-tools
REPLAYGAIN_DESC=	Enable (vorbis|mp3)gain support
REPLAYGAIN_RUN_DEPENDS=	mp3gain:audio/mp3gain \
			vorbisgain:audio/vorbisgain
SPEEX_RUN_DEPENDS=	speexenc:audio/speex

post-extract:
	@${LN} -sf abcde.conf ${WRKSRC}/abcde.conf.sample

post-patch:
	@${REINPLACE_CMD} -e \
		's|\([[:space:]]\)\(/etc/abcde.conf\)|\1${PREFIX}\2|' \
		${WRKSRC}/abcde
	@${REINPLACE_CMD} -e \
		's|\(fI\)\(/etc/abcde.conf\)|\1${PREFIX}\2|' \
		${WRKSRC}/abcde.1

do-install:
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} abcde cddb-tool \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_DATA} abcde.conf.sample \
		${STAGEDIR}${PREFIX}/etc)
	(cd ${WRKSRC} && ${INSTALL_MAN} abcde.1 cddb-tool.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)

.include <bsd.port.mk>
