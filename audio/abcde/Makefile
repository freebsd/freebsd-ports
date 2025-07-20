PORTNAME=	abcde
DISTVERSION=	2.9.3
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://abcde.einval.com/download/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Front-end shell script to encode CDs in flac/mp3/ogg/speex format
WWW=		https://abcde.einval.com/

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual

RUN_DEPENDS=	cd-discid:audio/cd-discid \
		cdparanoia:audio/cdparanoia \
		lame:audio/lame \
		eyeD3:audio/py-eyed3 \
		oggenc:audio/vorbis-tools \
		bash:shells/bash \
		eject:sysutils/eject

USES=		shebangfix

NO_ARCH=	yes
NO_BUILD=	yes
SHEBANG_FILES=	abcde abcde-musicbrainz-tool cddb-tool

SUB_FILES=	pkg-message

OPTIONS_GROUP=		CODEC RIPPER
OPTIONS_GROUP_CODEC=	AAC FLAC OPUS SPEEX
OPTIONS_GROUP_RIPPER=	CDDA2WAV DAGRAB
OPTIONS_DEFINE=		MUSICBRAINZ NORMALIZE REPLAYGAIN
OPTIONS_DEFAULT=	MUSICBRAINZ

AAC_RUN_DEPENDS=	faac:audio/faac
CDDA2WAV_RUN_DEPENDS=	cdda2wav:sysutils/cdrtools
DAGRAB_RUN_DEPENDS=	dagrab:audio/dagrab
FLAC_RUN_DEPENDS=	flac:audio/flac
MUSICBRAINZ_DESC=	Enable MusicBrainz DiscID support
MUSICBRAINZ_USES=	perl5
MUSICBRAINZ_USE=	PERL5=run
MUSICBRAINZ_RUN_DEPENDS=	\
		p5-MusicBrainz-DiscID>=0:audio/p5-MusicBrainz-DiscID \
		p5-WebService-MusicBrainz>=1:www/p5-WebService-MusicBrainz
NORMALIZE_DESC=		Enable normalize support
NORMALIZE_RUN_DEPENDS=	normalize:audio/normalize
OPUS_RUN_DEPENDS=	opusenc:audio/opus-tools
REPLAYGAIN_DESC=	Enable (vorbis|mp3)gain support
REPLAYGAIN_RUN_DEPENDS=	mp3gain:audio/mp3gain \
			vorbisgain:audio/vorbisgain
SPEEX_RUN_DEPENDS=	speexenc:audio/speex

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
	(cd ${WRKSRC} && ${INSTALL_DATA} abcde.conf \
		${STAGEDIR}${PREFIX}/etc/abcde.conf.sample)
	(cd ${WRKSRC} && ${INSTALL_MAN} abcde.1 cddb-tool.1 \
		${STAGEDIR}${PREFIX}/share/man/man1)
post-install-MUSICBRAINZ-on:
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} abcde-musicbrainz-tool \
		${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.mk>
