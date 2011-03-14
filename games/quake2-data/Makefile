# New ports collection makefile for:	quake2-data
# Date created:				28 Sep 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	3.20
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE:S|$|:data,src|}
MASTER_SITE_SUBDIR=	quake2/:data \
			quake2/source/:src
PKGNAMEPREFIX=	${Q2PKGNAMEPREFIX}
DISTFILES=	${Q2_UPDATE}:data \
		${Q2_SRC}:src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake II data files

#XXX need info-unzip for q2-314-demo-x86.exe
USE_ZIP=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	MANUAL "Install game manual" off \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SHAREWARE "Install demo version of the game data" off

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}
DATADIR=	${Q2DIR}
DOCSDIR=	${PREFIX}/share/doc/${LATEST_LINK}

Q2_DEMO=	q2-314-demo-x86.exe
Q2_SRC=		q2src${PORTVERSION:S/.//}.shar.Z
Q2_UPDATE=	q2-${PORTVERSION}-x86-full.exe

.include "Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITH_MANUAL) || defined(WITH_SHAREWARE)
DISTFILES+=	${Q2_DEMO}:data
.endif

.if defined(WITH_MANUAL)
PLIST_SUB+=	MANUAL=""
.else
PLIST_SUB+=	MANUAL="@comment "
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
MAKE_ENV+=	WITH_OPTIMIZED_CFLAGS=yes
.endif

.if defined(WITH_SHAREWARE)
PLIST_SUB+=	FULL="@comment " \
		SHAREWARE=""
.else
PLIST_SUB+=	FULL="" \
		SHAREWARE="@comment "
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && \
		uncompress -c ${DISTDIR}/${Q2_SRC} | ${TAIL} +434 | ${SH}
	@${UNZIP_CMD} -q -d ${WRKDIR} \
		${DISTDIR}/${Q2_UPDATE} baseq2/* -x *.dll
.if defined(WITH_MANUAL)
	@${UNZIP_CMD} -ajq -d ${WRKDIR}/DOCS \
		${DISTDIR}/${Q2_DEMO} Install/Data/DOCS/*
.endif
.if defined(WITH_SHAREWARE)
	@${RM} ${WRKDIR}/baseq2/pak[^0].pak
	@${UNZIP_CMD} -jq -d ${WRKDIR}/baseq2 \
		${DISTDIR}/${Q2_DEMO} Install/Data/baseq2/pak0.pak
.endif

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's/__linux__/__unix__/' ${WRKSRC}/q_shared.[ch]

do-install:
	${MKDIR} ${DATADIR}/baseq2
	${INSTALL_PROGRAM} ${WRKSRC}/game.so ${DATADIR}/baseq2
	${CP} -R ${WRKSRC}/baseq2/* ${DATADIR}/baseq2
.if defined(WITH_MANUAL)
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/DOCS ${DOCSDIR}/manual
.endif

post-install:
.if !defined(WITH_SHAREWARE)
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}
.endif

.include <bsd.port.post.mk>
