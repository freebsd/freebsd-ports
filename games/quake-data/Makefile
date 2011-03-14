# New ports collection makefile for:	quake-data
# Date created:				11 Sep 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/quake/data/:qs
PKGNAMEPREFIX=	${Q1PKGNAMEPREFIX}
DISTNAME=	quakesw-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:qs
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake data files

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	FULL "Install full version" off \
		QUAKEWORLD "Install QuakeWorld data" on \
		QUAKEWORLD_SKINS "Install QuakeWorld skins" on

DATADIR=	${Q1DIR}

PROGFILE=	qwsv-2.30-glibc-i386-unknown-linux2.0.tar.gz
SKINFILES=	skinbase.zip qw_skins.zip

.include "Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITH_FULL)
DISTFILES+=	pak1.pak
PLIST_SUB+=	FULL=""
.else
PLIST_SUB+=	FULL="@comment "
.endif

.if !defined(WITHOUT_QUAKEWORLD)
MASTER_SITES+=	${MASTER_SITE_IDSOFTWARE:S|$|quakeworld/unix/:qw|}
DISTFILES+=	${PROGFILE}:qw
EXTRACT_ONLY+=	${PROGFILE}
PLIST_SUB+=	QUAKEWORLD=""

.if !defined(WITHOUT_QUAKEWORLD_SKINS)
MASTER_SITES+=	${MASTER_SITE_IDSOFTWARE:S|$|quakeworld/skins/:skins|}
DISTFILES+=	${SKINFILES:S/$/:skins/}
EXTRACT_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
PLIST_SUB+=	QUAKEWORLD_SKINS=""
.else
PLIST_SUB+=	QUAKEWORLD_SKINS="@comment "
.endif

.else
PLIST_SUB+=	QUAKEWORLD="@comment "
.endif	# !WITHOUT_QUAKEWORLD

pre-fetch:
.if defined(WITH_FULL) && !exists(${DISTDIR}/${DIST_SUBDIR}/pak1.pak)
	@${ECHO_CMD}
	@${ECHO_CMD} You need to copy the file pak1.pak from the original Quake CDROM to ${DISTDIR}/${DIST_SUBDIR} in order to install this port. | ${FMT}
	@${ECHO_CMD}
	@${FALSE}
.endif

do-install:
	${MKDIR} ${DATADIR}/id1
	${INSTALL_DATA} ${WRKSRC}/id1/pak0.pak ${DATADIR}/id1
.if defined(WITH_FULL)
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/pak1.pak ${DATADIR}/id1
.endif
.if !defined(WITHOUT_QUAKEWORLD)
	@${MKDIR} ${DATADIR}/qw
	@${INSTALL_DATA} ${WRKSRC}/qw/qwprogs.dat ${DATADIR}/qw
	@${MKDIR} ${DATADIR}/qw/skins
	@${INSTALL_SCRIPT} ${WRKSRC}/qw/skins/fixskins.sh ${DATADIR}/qw/skins
. if !defined(WITHOUT_QUAKEWORLD_SKINS)
.   for f in ${SKINFILES}
	@${UNZIP_CMD} -nq ${DISTDIR}/${DIST_SUBDIR}/${f} -d ${DATADIR}/qw/skins
.   endfor
	@(cd ${DATADIR}/qw/skins && LANG=C ./fixskins.sh *)
. endif
.endif	# !WITHOUT_QUAKEWORLD

.include <bsd.port.post.mk>
