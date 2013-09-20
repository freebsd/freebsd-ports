# Created by: alepulver
# $FreeBSD$

PORTNAME=	iourbanterror
PORTVERSION=	${GAMEVERSION}.g${GITREVISION}
PORTEPOCH=	1
CATEGORIES=	games
DISTNAME=	ioquake3-devel-GIT${GITREVISION}

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Quake 3 engine modified for Urban Terror (based on ioquake3)

RUN_DEPENDS=	${Q3DIR}/q3ut4:${PORTSDIR}/games/urbanterror-data

MASTERDIR=	${.CURDIR}/../ioquake3-devel
DISTINFO_FILE=	${.CURDIR}/../ioquake3-devel/distinfo

IOQ3?=		CLIENT DLRENDERER OPUS OPENGL2

# The docs belong to ioquake3
OPTIONS_EXCLUDE=	DOCS
GAMEVERSION=	4.2.014
Q3ENGINEVER=	GIT${GITREVISION}+${GAMEVERSION}
Q3TOTALCONV=	yes
Q3DIR=		${PREFIX}/share/quake3
Q3ICON=		${PREFIX}/share/quake3/q3ut4/q3ut.ico
Q3CLIENT=	ioUrbanTerror
Q3SERVER=	ioUrTded
Q3BASE=		q3ut4
BINSUFFIX=
HOMEPATH=	/.ioUrbanTerror

MAKE_ARGS+=	BUILD_MISSIONPACK=0 \
		BUILD_STANDALONE=1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} \
		-e 's/ioquake3/${Q3CLIENT}/g' \
		-e 's/ioq3ded/${Q3SERVER}/g' \
		-e 's/baseq3/${Q3BASE}/g' \
		"${WRKSRC}/Makefile"

.include "${MASTERDIR}/Makefile"
