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
NO_STAGE=	yes
GROUPS=		${USERS}
SHAREOWN=	${USERS}
SHAREGRP=	${SHAREOWN}
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	8K 16K 32K 48K

8K_DESC=	8000Hz Music
16K_DESC=	16000Hz Music
32K_DESC=	32000Hz Music
48K_DESC=	48000Hz Music

OPTIONS_DEFAULT=	8K 16K
NO_OPTIONS_SORT=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:M8K}
DISTFILES+=	freeswitch-sounds-music-8000-${DISTVERSION}${EXTRACT_SUFX}
.endif

.if ${PORT_OPTIONS:M16K}
DISTFILES+=	freeswitch-sounds-music-16000-${DISTVERSION}${EXTRACT_SUFX}
.endif

.if ${PORT_OPTIONS:M32K}
DISTFILES+=	freeswitch-sounds-music-32000-${DISTVERSION}${EXTRACT_SUFX}
.endif

.if ${PORT_OPTIONS:M48K}
DISTFILES+=	freeswitch-sounds-music-48000-${DISTVERSION}${EXTRACT_SUFX}
.endif

.for opt in ${ALL_OPTIONS}
.if ${PORT_OPTIONS:M${opt}}
PLIST_SUB+=	${opt}=""
.else
PLIST_SUB+=	${opt}="@comment "
.endif
.endfor

do-install:
	@${ECHO_MSG} "Installing files..."
	${MKDIR} ${DATADIR}/sounds
	${TOUCH} ${DATADIR}/sounds/.freeswitch-music
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${DATADIR}/sounds/)

.include <bsd.port.mk>
