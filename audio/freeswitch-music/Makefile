# Ports collection makefile for: freeswitch-sounds
# Date created: May 11, 2009
# Whom: Eric F Crist <ecrist@secure-computing.net>
#
# $FreeBSD$
#

PORTNAME=	freeswitch
PORTVERSION=	1.0.8
CATEGORIES=	audio
MASTER_SITES=	http://files.freeswitch.org/
PKGNAMESUFFIX=	-music
DIST_SUBDIR=	freeswitch-music

MAINTAINER=	ecrist@secure-computing.net
COMMENT=	FreeSwitch Music - All Bitrates

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

OPTIONS=	8K           "Install 8000Hz Music" on \
		16K          "Install 16000Hz Music" on \
		32K          "Install 32000Hz Music" on \
		48K          "Install 48000Hz Music" on

.include <bsd.port.options.mk>
.if defined(WITH_8K)
DISTFILES+=	${PORTNAME}-sounds${PKGNAMESUFFIX}-8000-${PORTVERSION}${EXTRACT_SUFX}
.endif
.if defined(WITH_16K)
DISTFILES+=	${PORTNAME}-sounds${PKGNAMESUFFIX}-16000-${PORTVERSION}${EXTRACT_SUFX}
.endif
.if defined(WITH_32K)
DISTFILES+=	${PORTNAME}-sounds${PKGNAMESUFFIX}-32000-${PORTVERSION}${EXTRACT_SUFX}
.endif
.if defined(WITH_48K)
DISTFILES+=	${PORTNAME}-sounds${PKGNAMESUFFIX}-48000-${PORTVERSION}${EXTRACT_SUFX}
.endif

#RUN_DEPENDS+= freeswitch:${PORTSDIR}/net/freeswitch-core

do-install:
	@${ECHO_MSG} "Installing files..."
	${MKDIR} ${PREFIX}/share/${PORTNAME}/sounds
	(cd ${WRKDIR} &&${COPYTREE_SHARE} \* ${DATADIR}/sounds/)

.include <bsd.port.mk>
