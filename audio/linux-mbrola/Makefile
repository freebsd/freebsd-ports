# New ports collection makefile for:		linux-mbrola
# Date created:					2003-10-05
# Whom:						trevor
#
# $FreeBSD$
#

CATEGORIES=	audio accessibility linux
MASTER_SITES=	http://mambo.ucsc.edu/psl/mbrola/bin/pclinux/ \
		http://www.festvox.org/mbrola/bin/pclinux/ \
		ftp://ftp.loria.fr/pub/pc/mbrpsola/bin/pclinux/ \
		ftp://tcts.fpms.ac.be/pub/mbrola/bin/pclinux/
PKGNAMEPREFIX=	linux-

COMMENT=	MBROLA speech synthesizer for Linux

CONFLICTS=	mbrola-*
DIST_SUBDIR=	mbrola-linux
MASTERDIR=	${PORTSDIR}/audio/mbrola
MD5_FILE=	${.CURDIR}/distinfo
ONLY_FOR_ARCHS=	alpha i386 ppc sparc64
USE_LINUX=	y
USE_ZIP=	y

MASTERDIR=	${.CURDIR}/../mbrola
.include "${MASTERDIR}/Makefile"
