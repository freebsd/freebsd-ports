# New ports collection makefile for:	subversion-freebsd
# Date created:				29 May 2008
# Whom:					dougb@FreeBSD.org
#
# $FreeBSD$

PORTREVISION=	1
PKGNAMESUFFIX=	-freebsd

COMMENT=	Version control system with FreeBSD Project repo customizations

MASTERDIR=	${.CURDIR}/../subversion

DESCR=		${.CURDIR}/pkg-descr

# Patches required for use with the FreeBSD Project repository only
#PATCH_SITES=		http://lev.serebryakov.spb.ru/download/
PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	lev
PATCHFILES+=		svn_hacks_1.4.diff

CONFLICTS?=	subversion-[0-9]* subversion-devel-[0-9]*

MD5_FILE=	${MASTERDIR}/distinfo

.include "${MASTERDIR}/Makefile"
