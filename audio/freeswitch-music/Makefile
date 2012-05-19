# Ports collection makefile for: freeswitch-music
# Date created: May 11, 2009
# Whom: Eric F Crist <ecrist@secure-computing.net>
#
# $FreeBSD$
#

PORTNAME=	freeswitch
PORTVERSION=	1.0.8
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://files.freeswitch.org/
PKGNAMESUFFIX=	-music
DIST_SUBDIR=	freeswitch

MAINTAINER=	r.neese@gmail.com
COMMENT=	FreeSwitch Music - All Bitrates

RUN_DEPENDS=	${LOCALBASE}/bin/freeswitch:${PORTSDIR}/net/freeswitch-core

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
SHAREOWN=	${PORTNAME}
SHAREGRP=	${SHAREOWN}

OPTIONS=	8K           "Install 8000Hz Music" on \
		16K          "Install 16000Hz Music" on \
		32K          "Install 32000Hz Music" on \
		48K          "Install 48000Hz Music" on

.include <bsd.port.options.mk>

.if defined(WITH_8K)
DISTFILES+=	freeswitch-sounds-music-8000-${DISTVERSION}${EXTRACT_SUFX}
.endif

.if defined(WITH_16K)
DISTFILES+=	freeswitch-sounds-music-16000-${DISTVERSION}${EXTRACT_SUFX}
.endif

.if defined(WITH_32K)
DISTFILES+=	freeswitch-sounds-music-32000-${DISTVERSION}${EXTRACT_SUFX}
.endif

.if defined(WITH_48K)
DISTFILES+=	freeswitch-sounds-music-48000-${DISTVERSION}${EXTRACT_SUFX}
.endif

.for i in 8K 16K 32K 48K
.  if !defined(WITH_${i})
PLIST_SUB+=	WITH_${i}="@comment "
.  else
PLIST_SUB+=	WITH_${i}=""
.  endif
.endfor

do-install:
	@${ECHO_MSG} "Installing files..."
	${MKDIR} ${DATADIR}/sounds
	${TOUCH} ${DATADIR}/sounds/.freeswitch-music
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${DATADIR}/sounds/)

.include <bsd.port.mk>
