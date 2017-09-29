# Created by: Josh Tolbert
# $FreeBSD$

PORTNAME=	openarena
DISTVERSION=	${GAMEVERSION}.s${SVNREVISION}
PORTREVISION=	3
PORTEPOCH=	1
MASTER_SITES=	SF/oarena/src \
		http://files.poulsander.com/~poul19/public_files/oa/dev088/
DISTNAME=	${PORTNAME}-engine-source-${GAMEVERSION}
EXTRACT_SUFX=	.tar.bz2 # override master port

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake3 total conversion based on the ioquake3 engine

LICENSE?=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/${DATADIR_REL}/${Q3BASE}/pak0.pk3:games/openarena-data

USES=		tar:bzip2

MASTERDIR=	${.CURDIR}/../ioquake3
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DISTINFO_FILE=	${.CURDIR}/../${PORTNAME}/distinfo
PATCHDIR=	${.CURDIR}/../${PORTNAME}/files
PKGMESSAGE=	${.CURDIR}/../${PORTNAME}/pkg-message

IOQ3?=		CLIENT
IOQ3ARCH?=	${ARCH}
IOQ3SDL=	sdl
# OpenArena doc is too messy to bother
OPTIONS_EXCLUDE=	DOCS

GAMEVERSION=	0.8.8
SVNREVISION=	1910
Q3ENGINEVER=	SVN${SVNREVISION}+${GAMEVERSION}
Q3TOTALCONV=	yes
Q3CLIENT=	openarena
Q3SERVER=	oa_ded
Q3BASE=		baseoa
Q3DIR=		${DATADIR}
# No icon included with OpenArena
Q3ICON=

pre-patch:
	@${FIND} ${WRKSRC} -name \*.orig -delete

.include "${MASTERDIR}/Makefile"
