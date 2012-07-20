# New ports collection makefile for:	ioquake3-devel
# Date created:				31 Aug 2009
# Whom:					Dominic Fandrey
#
# $FreeBSD$
#

PORTNAME?=	ioquake3-devel
DISTVERSION?=	1.36_SVN${SVNREVISION}
PORTREVISION?=	1
MASTER_SITES?=	ftp://deponie.yamagi.org/freebsd/distfiles/ioquake3/ \
		http://deponie.yamagi.org/freebsd/distfiles/ioquake3/

MAINTAINER?=	kamikaze@bsdforen.de
COMMENT?=	Development SVN snapshots of ioquake3

MASTERDIR=	${.CURDIR}/../ioquake3
DESCR?=		${.CURDIR}/../${PORTNAME}/pkg-descr
DISTINFO_FILE?=	${.CURDIR}/../${PORTNAME}/distinfo
PATCHDIR?=	${WRKDIR}/freebsd-patchset/
PKGMESSAGE?=	${.CURDIR}/../${PORTNAME}/pkg-message

SVNREVISION?=	2244
BINSUFFIX?=	-devel

HAS_DLRENDERER?=	yes

.include "${MASTERDIR}/Makefile"
