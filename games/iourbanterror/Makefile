# New ports collection makefile for:	ioquake3
# Date created:				3 Jun 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	iourbanterror
PORTVERSION=	4.1
DISTVERSION=	1.36_SVN${SVNREVISION}+${PORTVERSION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games
DISTNAME=	ioquake3-devel-1.36_SVN${SVNREVISION}

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Quake 3 engine modified for Urban Terror (based on ioquake3)

RUN_DEPENDS=	${Q3DIR}/q3ut4:${PORTSDIR}/games/urbanterror-data

PLIST=		${.CURDIR}/pkg-plist

# The docs belong to ioquake3
NOPORTDOCS=	yes

Q3TOTALCONV=	yes
Q3DIR=		${PREFIX}/share/quake3
Q3ICON=		${PREFIX}/share/quake3/q3ut4/q3ut.ico
Q3CLIENT=	ioUrbanTerror
Q3SERVER=	ioUrTded
Q3TOOLS=
Q3BASE=		q3ut4
BINSUFFIX=
HOMEPATH=	/.ioUrbanTerror

MAKE_ARGS+=	BUILD_MISSIONPACK=0 \
		BUILD_STANDALONE=1

UTPATCHES!=	echo ${.CURDIR}/files/*

post-patch:
.for _file in ${UTPATCHES}
	@${PATCH} -sd "${WRKSRC}" < ${_file}
.endfor
	@${REINPLACE_CMD} \
		-e 's/ioquake3/${Q3CLIENT}/g' \
		-e 's/ioq3ded/${Q3SERVER}/g' \
		-e 's/baseq3/${Q3BASE}/g' \
		"${WRKSRC}/Makefile"

.include "../ioquake3-devel/Makefile"
