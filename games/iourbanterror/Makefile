# Created by: alepulver
# $FreeBSD$

PORTNAME=	iourbanterror
PORTVERSION=	${GAMEVERSION}.${DISTVERSION}
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	games
DISTNAME=	ioquake3-${DISTVERSION}

MAINTAINER=	kami@FreeBSD.org
COMMENT=	Quake 3 engine modified for Urban Terror (based on ioquake3)

RUN_DEPENDS=	urbanterror-data>0:games/urbanterror-data

LICENSE?=	GPLv2

MASTERDIR=	${.CURDIR}/../ioquake3
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
PATCHDIR=	${.CURDIR}/../${PORTNAME}/files

IOQ3?=		CLIENT

# The docs belong to ioquake3
OPTIONS_EXCLUDE=	DOCS
GAMEVERSION=	4.2.023
Q3ENGINEVER=	${DISTVERSION}+${GAMEVERSION}
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

pre-patch:
	@(cd ${WRKSRC} && \
	for pfile in ${MASTERDIR}/files/patch-*; do \
		${PATCH} < $${pfile}; \
	done)
	@${FIND} ${WRKSRC} -name \*.orig -delete
	@${REINPLACE_CMD} \
		-e 's/ioquake3/${Q3CLIENT}/g' \
		-e 's/ioq3ded/${Q3SERVER}/g' \
		-e 's/baseq3/${Q3BASE}/g' \
		"${WRKSRC}/Makefile"

.include "${MASTERDIR}/Makefile"
