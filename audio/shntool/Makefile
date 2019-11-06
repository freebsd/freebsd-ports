# Created by: Bill Fenner <fenner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shntool
PORTVERSION=	3.0.10
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.etree.org/shnutils/shntool/dist/src/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Multi-purpose WAVE data processing and reporting utility

BROKEN=		unfetchable

GNU_CONFIGURE=	yes
SHN_ALIASES=	cat cmp conv cue fix gen hash info join len pad split \
		strip tool trim

PLIST_FILES=	${SHN_ALIASES:S|^|bin/shn|} \
		man/man1/shntool.1.gz

OPTIONS_DEFINE=	AIFF ALAC APE FLAC KXS LA LPAC OFR SHN TTA WAVPACK

AIFF_DESC=	AIFF audio format support (via SoX)
KXS_DESC=	Kexis audio format support
LA_DESC=	Laudio audio format support
LPAC_DESC=	LPAC audio format support
OFR_DESC=	OptimFROG audio format support
SHN_DESC=	Shorten audio compressor support

AIFF_RUN_DEPENDS=	sox:audio/sox
ALAC_RUN_DEPENDS=	alacconvert:audio/alac
APE_RUN_DEPENDS=	mac:audio/mac
FLAC_RUN_DEPENDS=	flac:audio/flac
KXS_RUN_DEPENDS=	kexis:audio/kexis
LA_RUN_DEPENDS=		laudio:audio/linux-laudio
LPAC_RUN_DEPENDS=	lpac:audio/lpac
OFR_RUN_DEPENDS=	ofr:audio/optimfrog
SHN_RUN_DEPENDS=	shorten:audio/shorten
TTA_RUN_DEPENDS=	ttaenc:audio/tta
WAVPACK_RUN_DEPENDS=	wavpack:audio/wavpack

.include <bsd.port.mk>
