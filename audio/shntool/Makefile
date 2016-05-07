# Created by: Bill Fenner <fenner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shntool
PORTVERSION=	3.0.10
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.etree.org/shnutils/shntool/dist/src/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Multi-purpose WAVE data processing and reporting utility

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

RDEP_MAPPING=	AIFF:sox ALAC:alac APE:mac FLAC KXS:kexis \
		LA:laudio:linux-laudio LPAC OFR:ofr:optimfrog \
		SHN:shorten TTA:ttaenc:tta WAVPACK

.include <bsd.port.options.mk>

.for o in ${PORT_OPTIONS}
m=	${RDEP_MAPPING:M${o}*}
.if ${m}
b=	${m:C/^[A-Z]*://:C/:.*//:tl}
p=	${m:C/^[A-Z]*://:C/.*://:tl}
RUN_DEPENDS+=	${b}:audio/${p}
RUN_DEPENDS:=	${RUN_DEPENDS}
.endif
.endfor

.include <bsd.port.mk>
