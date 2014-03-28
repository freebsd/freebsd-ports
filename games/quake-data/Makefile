# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake data files

BUILD_DEPENDS=	${UNZIP_CMD}:${PORTSDIR}/archivers/unzip

DATADIR=	${Q1DIR}
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PROGFILE=	qwsv-2.30-glibc-i386-unknown-linux2.0.tar.gz
SKINFILES=	skinbase.zip qw_skins.zip

OPTIONS_DEFINE=	FULLGAME QW_DATA QW_SKINS
OPTIONS_DEFAULT=	QW_DATA QW_SKINS

FULLGAME_DESC=	Install full game version
QW_DATA_DESC=	Install QuakeWorld data
QW_SKINS_DESC=	Install QuakeWorld skins

.include "Makefile.include"	# must be included before bsd.port.options.mk
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFULLGAME}
DISTFILES+=	pak1.pak
PLIST_FILES+=	%%DATADIR%%/id1/pak1.pak
.endif

.if ${PORT_OPTIONS:MQW_DATA}
MASTER_SITES+=	${MASTER_SITE_IDSOFTWARE:S|$|quakeworld/unix/:qw|}
DISTFILES+=	${PROGFILE}:qw
EXTRACT_ONLY+=	${PROGFILE}
PLIST_SUB+=	QUAKEWORLD=""
.  if ${PORT_OPTIONS:MQW_SKINS}
MASTER_SITES+=	${MASTER_SITE_IDSOFTWARE:S|$|quakeworld/skins/:skins|}
DISTFILES+=	${SKINFILES:S/$/:skins/}
EXTRACT_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
PLIST_SUB+=	QUAKEWORLD_SKINS=""
.  else
PLIST_SUB+=	QUAKEWORLD_SKINS="@comment "
.  endif
.else
PLIST_SUB+=	QUAKEWORLD="@comment "
.endif

pre-fetch:
.if ${PORT_OPTIONS:MFULLGAME} && !exists(${_DISTDIR}/pak1.pak)
	@${ECHO_CMD}
	@${ECHO_CMD} You need to copy the file pak1.pak from the \
		original Quake CDROM to ${_DISTDIR} in order to \
		install this port. | ${FMT}
	@${ECHO_CMD}
	@${FALSE}
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/id1
	${INSTALL_DATA} ${WRKSRC}/id1/pak0.pak ${STAGEDIR}${DATADIR}/id1
.if ${PORT_OPTIONS:MFULLGAME}
	${INSTALL_DATA} ${_DISTDIR}/pak1.pak ${STAGEDIR}${DATADIR}/id1
.endif
.if ${PORT_OPTIONS:MQW_DATA}
	@${MKDIR} ${STAGEDIR}${DATADIR}/qw
	${INSTALL_DATA} ${WRKSRC}/qw/qwprogs.dat ${STAGEDIR}${DATADIR}/qw
	@${MKDIR} ${STAGEDIR}${DATADIR}/qw/skins
	${INSTALL_SCRIPT} ${WRKSRC}/qw/skins/fixskins.sh \
		${STAGEDIR}${DATADIR}/qw/skins
.  if ${PORT_OPTIONS:MQW_SKINS}
.    for f in ${SKINFILES}
	@${UNZIP_CMD} -nq ${_DISTDIR}/${f} -d ${STAGEDIR}${DATADIR}/qw/skins
.    endfor
	@(cd ${STAGEDIR}${DATADIR}/qw/skins && LANG=C ./fixskins.sh *)
.  endif
.endif

.include <bsd.port.mk>
