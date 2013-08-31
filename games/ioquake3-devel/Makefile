# Created by: Dominic Fandrey
# $FreeBSD$

PORTNAME?=	ioquake3-devel
DISTVERSION?=	GIT${GITREVISION}
PORTREVISION?=	0
MASTER_SITES?=	ftp://deponie.yamagi.org/freebsd/distfiles/ioquake3/ \
		http://deponie.yamagi.org/freebsd/distfiles/ioquake3/
EXTRACT_SUFX?=	.tar.xz

MAINTAINER?=	kamikaze@bsdforen.de
COMMENT?=	Development GIT snapshots of ioquake3

MASTERDIR=	${.CURDIR}/../ioquake3
DESCR?=		${.CURDIR}/../${PORTNAME}/pkg-descr
DISTINFO_FILE?=	${.CURDIR}/../${PORTNAME}/distinfo
PATCHDIR?=	${.CURDIR}/../${PORTNAME}/files
PKGMESSAGE?=	${.CURDIR}/../${PORTNAME}/pkg-message

GITREVISION?=	2178
BINSUFFIX?=	-devel

IOQ3?=		CLIENT TOOLS DLRENDERER GAMELIBS OPUS OPENGL2
IOQ3ARCH?=	${ARCH:S/i386/x86/:S/amd64/x86_64/}

.include "${MASTERDIR}/Makefile"
