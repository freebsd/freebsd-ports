# Created by: Nik Clayton <nik@FreeBSD.org>
# $FreeBSD$

PORTNAME=	data
DISTVERSION=	1.32b-3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	IDSOFTWARE/quake3/linux
PKGNAMEPREFIX=	${Q3PKGNAMEPREFIX}
DISTNAME=	linuxq3apoint-${DISTVERSION}.x86
EXTRACT_SUFX=	.run

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake III Arena data files

DATADIR=	${Q3DIR}
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	TEAMARENA
OPTIONS_DEFAULT=	TEAMARENA
OPTIONS_SUB=	yes

TEAMARENA_DESC=		Install Quake III Team Arena data files

.include "Makefile.include"	# must be included before bsd.port.options.mk
.include <bsd.port.options.mk>

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${TAIL} +356 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} xzf - -C ${WRKDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -a ${WRKSRC}/baseq3 ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/quake3.xpm ${STAGEDIR}${PREFIX}/share/pixmaps
.if ${PORT_OPTIONS:MTEAMARENA}
	${CP} -a ${WRKSRC}/missionpack ${STAGEDIR}${DATADIR}
.endif

.include <bsd.port.mk>
