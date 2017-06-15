# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	1.0.6
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/quake/data/:qs
PKGNAMEPREFIX=	${Q1PKGNAMEPREFIX}
DISTNAME=	quakesw-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:qs
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake data files

DATADIR=	${Q1DIR}
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PROGFILE=	qwsv-2.30-glibc-i386-unknown-linux2.0.tar.gz
SKINFILES=	skinbase.zip qw_skins.zip

OPTIONS_DEFINE=	FULLGAME QW_DATA QW_SKINS
OPTIONS_DEFAULT=	QW_DATA QW_SKINS

FULLGAME_DESC=	Install full game version
QW_DATA_DESC=	Install QuakeWorld data
QW_SKINS_DESC=	Install QuakeWorld skins (implies QW_DATA)

.include "Makefile.include"	# must be included before bsd.port.options.mk
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFULLGAME}
DISTFILES+=	pak1.pak
PLIST_FILES+=	%%DATADIR%%/id1/pak1.pak
.endif

.if ${PORT_OPTIONS:MQW_DATA} || ${PORT_OPTIONS:MQW_SKINS}
MASTER_SITES+=	IDSOFTWARE/quakeworld/unix/:qw
DISTFILES+=	${PROGFILE}:qw
EXTRACT_ONLY+=	${PROGFILE}
COMMENT:=	${COMMENT:S,Quake,& and &World,}
PLIST_SUB+=	QUAKEWORLD=""
.else
PLIST_SUB+=	QUAKEWORLD="@comment "
.endif

.if ${PORT_OPTIONS:MQW_SKINS}
MASTER_SITES+=	IDSOFTWARE/quakeworld/skins/:skins
DISTFILES+=	${SKINFILES:S/$/:skins/}
PLIST_SUB+=	QUAKEWORLD_SKINS=""
COMMENT+=	and skins
.else
PLIST_SUB+=	QUAKEWORLD_SKINS="@comment "
.endif

pre-fetch:
.if ${PORT_OPTIONS:MFULLGAME} && !exists(${_DISTDIR}/pak1.pak)
	@${ECHO_CMD}
	@${ECHO_CMD} You need to copy the file pak1.pak from the \
		original Quake CDROM to ${_DISTDIR} in order to \
		install this port with full game support. | ${FMT}
	@${ECHO_CMD}
	@${FALSE}
.endif

post-extract:
.if ${PORT_OPTIONS:MQW_SKINS}
.  for f in ${SKINFILES}
	${TAR} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${f} \
		${EXTRACT_AFTER_ARGS} -C ${WRKSRC}/qw/skins
.  endfor
	(cd ${WRKSRC}/qw/skins && ${SH} fixskins.sh)
.endif

# Since these files are not generated, only unpacked, install(1) them with
# `-p' switch to preserve their modification times; ditto for cp(1).
do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/id1
	${INSTALL_DATA} -p ${WRKSRC}/id1/pak0.pak ${STAGEDIR}${DATADIR}/id1
.if ${PORT_OPTIONS:MFULLGAME}
	${INSTALL_DATA} -p ${_DISTDIR}/pak1.pak ${STAGEDIR}${DATADIR}/id1
.endif
.if ${PORT_OPTIONS:MQW_DATA} || ${PORT_OPTIONS:MQW_SKINS}
	@${MKDIR} ${STAGEDIR}${DATADIR}/qw
	${INSTALL_DATA} -p ${WRKSRC}/qw/qwprogs.dat ${STAGEDIR}${DATADIR}/qw
	${CP} -a ${WRKSRC}/qw/skins ${STAGEDIR}${DATADIR}/qw
.endif

.include <bsd.port.mk>
