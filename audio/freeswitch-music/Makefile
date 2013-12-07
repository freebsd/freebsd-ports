# Created by: Eric F Crist <ecrist@secure-computing.net>
# $FreeBSD$

PORTNAME=	freeswitch
PORTVERSION=	1.0.8
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://files.freeswitch.org/
PKGNAMESUFFIX=	-music
DIST_SUBDIR=	freeswitch

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeSwitch Music - All Bitrates

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USERS=		${PORTNAME}
GROUPS=		${USERS}
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	8K 16K 32K 48K

8K_DESC=	8000Hz Music
16K_DESC=	16000Hz Music
32K_DESC=	32000Hz Music
48K_DESC=	48000Hz Music

OPTIONS_DEFAULT=	8K 16K
NO_OPTIONS_SORT=	yes

8K_DISTFILES=	freeswitch-sounds-music-8000-${DISTVERSION}${EXTRACT_SUFX}
16K_DISTFILES=	freeswitch-sounds-music-16000-${DISTVERSION}${EXTRACT_SUFX}
32K_DISTFILES=	freeswitch-sounds-music-32000-${DISTVERSION}${EXTRACT_SUFX}
48K_DISTFILES=	freeswitch-sounds-music-48000-${DISTVERSION}${EXTRACT_SUFX}

OPTIONS_SUB=	yes

do-install:
	@${ECHO_MSG} "Installing files..."
	@${MKDIR} ${STAGEDIR}${DATADIR}/sounds
	${TOUCH} ${STAGEDIR}${DATADIR}/sounds/.freeswitch-music
	cd ${WRKSRC} && ${COPYTREE_SHARE} music ${STAGEDIR}${DATADIR}/sounds

.include <bsd.port.mk>
