# New ports collection makefile for:	openarena
# Date created:				2007-08-01
# Whom:					Josh Tolbert <hemi@puresimplicity.net>
#
# $FreeBSD$
#

PORTNAME=	openarena
PORTVERSION=	${GAMEVERSION}.s${SVNREVISION}
DISTVERSION=	1.36_SVN${SVNREVISION}+${GAMEVERSION}
PORTREVISION=	9
PORTEPOCH=	1
MASTER_SITES=	http://files.poulsander.com/~poul19/public_files/oa/dev081/
DISTNAME=	${PORTNAME}-engine-source-0.8.x-22
# Master port defines EXTRACT_SUFX unless already defined
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Quake3 total conversion based on the ioquake3 engine

RUN_DEPENDS=	${DATADIR}/${Q3BASE}/pak0.pk3:${PORTSDIR}/games/openarena-data

NO_GAMELIBS=	yes
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

# Dynamically loaded renderer not yet supported
WITHOUT_DLRENDERER=	yes

.include "../ioquake3/Makefile"
