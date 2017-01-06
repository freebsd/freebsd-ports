# Created by: Dominic Fandrey
# $FreeBSD$

PORTNAME?=	ioquake3-devel
DISTVERSION?=	GIT${GITREVISION}
PORTREVISION?=	0
MASTER_SITES?=

MAINTAINER?=	kami@FreeBSD.org
COMMENT?=	Development GIT snapshots of ioquake3

LICENSE?=	GPLv2

MASTERDIR=	${.CURDIR}/../ioquake3
DESCR?=		${.CURDIR}/../${PORTNAME}/pkg-descr
DISTINFO_FILE?=	${.CURDIR}/../${PORTNAME}/distinfo
PATCHDIR?=	${.CURDIR}/../${PORTNAME}/files
PKGMESSAGE?=	${.CURDIR}/../${PORTNAME}/pkg-message

GITREVISION?=	2904
BINSUFFIX?=	-devel

IOQ3?=		CLIENT TOOLS DLRENDERER GAMELIBS OPUS OPENGL2
IOQ3ARCH?=	${ARCH:S/i386/x86/:S/amd64/x86_64/}
IOQ3SDL?=	sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	lonkamikaze
GH_PROJECT=	ioq3-freebsd
GH_TAGNAME=	${GITREVISION}

Q3DOCS?=	README.md \
		id-readme.txt \
		md4-readme.txt \
		opengl2-readme.md \
		voip-readme.txt

.include "${MASTERDIR}/Makefile"
