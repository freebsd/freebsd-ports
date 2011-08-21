# New ports collection makefile for:	openarena
# Date created:				2007-08-01
# Whom:					Josh Tolbert <hemi@puresimplicity.net>
#
# $FreeBSD$
#

PORTNAME=	openarena
PORTVERSION=	${GAMEVERSION}.s${SVNREVISION}
DISTVERSION=	1.36_SVN${SVNREVISION}+${GAMEVERSION}
PORTREVISION=	8
PORTEPOCH=	1
MASTER_SITES=	http://files.poulsander.com/~poul19/public_files/oa/dev081/
DISTNAME=	${PORTNAME}-engine-source-0.8.x-21

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Quake3 total conversion based on the ioquake3 engine

RUN_DEPENDS=	${DATADIR}/${Q3BASE}/pak0.pk3:${PORTSDIR}/games/openarena-data

USE_BZIP2=	yes
USE_ZIP=	no
# OpenArena doc is too messy to bother
NOPORTDOCS=	yes

GAMEVERSION=	0.8.5
SVNREVISION=	1910
Q3TOTALCONV=	yes
Q3CLIENT=	openarena
Q3SERVER=	oa_ded
Q3TOOLS=
Q3BASE=		baseoa
Q3DIR=		${DATADIR}
# No icon included with OpenArena
Q3ICON=

.include "../ioquake3/Makefile"
