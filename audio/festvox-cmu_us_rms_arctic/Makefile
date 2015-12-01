# Created by: ?
# $FreeBSD$

VOICE=	cmu_us_rms_arctic
PORTREVISION=	0

COMMENT=	English male voice for festival

MASTERDIR=	${.CURDIR}/../festvox-cmu_us_slt_arctic
DESCR=	${.CURDIR}/pkg-descr
DISTINFO_FILE=	${.CURDIR}/distinfo
PLIST=	${.CURDIR}/pkg-plist
PKGMESSAGE=	${.CURDIR}/pkg-message

NODIRS=	cep dic emu/lab_hlb emu/pm_hlb emu f0 \
	festival/accents festival/coeffs festival/disttabs \
	festival/dur festival/f0 festival/feats festival/phrbrk \
	group lar lpc pm_lab prompt-cep prompt-lab prompt-utt \
	prompt-wav recording scratch/lab scratch/wav scratch versions wrd

.include "${MASTERDIR}/Makefile.common"
