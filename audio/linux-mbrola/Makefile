# New ports collection makefile for:		linux-mbrola
# Date created:					2003-10-05
# Whom:						trevor
#
# $FreeBSD$
#

CATEGORIES=	audio accessibility linux
MASTER_SITES=	http://tcts.fpms.ac.be/synthesis/mbrola/bin/pclinux/ \
		http://www.festvox.org/mbrola/bin/pclinux/
PKGNAMEPREFIX=	linux-

COMMENT=	MBROLA speech synthesizer for Linux

CONFLICTS=	mbrola-*
DIST_SUBDIR=	mbrola-linux
MASTERDIR=	${PORTSDIR}/audio/mbrola
MD5_FILE=	${.CURDIR}/distinfo
ONLY_FOR_ARCHS=	alpha i386
USE_LINUX=	yes
USE_ZIP=	yes

MASTERDIR=	${.CURDIR}/../mbrola
.include "${MASTERDIR}/Makefile"
