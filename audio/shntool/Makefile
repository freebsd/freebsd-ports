# Created by: Bill Fenner <fenner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shntool
PORTVERSION=	3.0.10
CATEGORIES=	audio
MASTER_SITES=	http://www.etree.org/shnutils/shntool/dist/src/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Multi-purpose .wav processing utility

GNU_CONFIGURE=	yes
SHN_ALIASES=	tool len fix hash pad join split cat cmp cue conv info strip gen trim
PLIST_FILES=	${SHN_ALIASES:S|^|bin/shn|}
MAN1=		shntool.1

OPTIONS_DEFINE=	AIFF SHN FLAC APE OFR LPAC WV ALAC LA TTA BONK KXS
AIFF_DESC=	AIFF support via sox
SHN_DESC=	Shorten support
OFR_DESC=	OptimFROG support
LPAC_DESC=	LPAC support
WV_DESC=	WavPack support
ALAC_DESC=	Apple Lossless Audio support
LA_DESC=	Laudio support
TTA_DESC=	TTA Lossless Audio support
BONK_DESC=	Bonk lossy/lossless audio support
KXS_DESC=	Kexis support

RDEP=	AIFF:sox SHN:shorten FLAC APE:mac OFR:ofr:optimfrog LPAC WV:wavpack \
	ALAC:alac LA:linux-laudio TTA:ttaenc:tta BONK KXS:kexis

NO_STAGE=	yes
.include <bsd.port.options.mk>

.for o in ${PORT_OPTIONS}
m=	${RDEP:M${o}*}
.if ${m}
b=	${m:C/^[A-Z]*://:C/:.*//:L}
p=	${m:C/^[A-Z]*://:C/.*://:L}
RUN_DEPENDS+=	${b}:${PORTSDIR}/audio/${p}
RUN_DEPENDS:=	${RUN_DEPENDS}
.endif
.endfor

.include <bsd.port.mk>
