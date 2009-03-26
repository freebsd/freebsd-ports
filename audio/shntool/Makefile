# New ports collection makefile for:	shntool
# Date created:		2 November 2000
# Whom:			Bill Fenner <fenner@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	shntool
PORTVERSION=	3.0.9
CATEGORIES=	audio
MASTER_SITES=	http://www.etree.org/shnutils/shntool/dist/src/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Multi-purpose .wav processing utility

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
SHN_ALIASES=	tool len fix hash pad join split cat cmp cue conv info strip gen trim
PLIST_FILES=	${SHN_ALIASES:S|^|bin/shn|}
MAN1=		shntool.1

OPTIONS=	AIFF "AIFF support via sox" off \
		SHN "Shorten support" off \
		FLAC "FLAC support" off \
		APE "Monkey's Audio support" off \
		OFR "OptimFROG support" off \
		LPAC "LPAC support" off \
		WV "WavPack support" off \
		ALAC "Apple Lossless Audio support" off \
		LA "Laudio support" off \
		TTA "TTA Lossless Audio support" off \
		BONK "Bonk lossy/lossless audio support" off \
		KXS "Kexis support" off
#		ALS "MPEG-4 Audio Lossless Coding support" off \
RDEP=	AIFF:sox SHN:shorten FLAC APE:mac OFR:ofr:optimfrog LPAC WV:wavpack \
	ALAC:alac LA:laudio TTA:ttaenc:tta ALS:mp4als BONK KXS:kexis

.include <bsd.port.pre.mk>

.for i in ${RDEP}
o=	${i:C/:.*//}
.	ifdef WITH_${o}
b=	${i:C/^[A-Z]*://:C/:.*//:L}
p=	${i:C/^[A-Z]*://:C/.*://:L}
RUN_DEPENDS+=	${b}:${PORTSDIR}/audio/${p}
RUN_DEPENDS:=	${RUN_DEPENDS}
.	endif
.endfor

.include <bsd.port.post.mk>
