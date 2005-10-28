# New ports collection makefile for:	Quake 3 paks
# Date created:				1st March 2003
# Whom:					nik@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	data
DISTVERSION=	1.32b-3
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/quake3/linux/
DISTNAME=	linuxq3apoint-${DISTVERSION}.x86
EXTRACT_SUFX=	.run

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Quake III Arena data files

BROKEN=		Unfetchable

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	TEAMARENA "Install Quake III Team Arena data files" on

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && ${TAIL} +356 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} zxf - >/dev/null

.include "Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITH_TEAMARENA)
PLIST_SUB+=	TEAMARENA=""
.else
PLIST_SUB+=	TEAMARENA="@comment "
.endif

do-install:
	@${MKDIR} ${DATADIR}
	@${CP} -R ${WRKSRC}/baseq3 ${DATADIR}
	@${MKDIR} ${PREFIX}/share/pixmaps
	@${INSTALL_DATA} ${WRKSRC}/quake3.xpm ${PREFIX}/share/pixmaps
.if defined(WITH_TEAMARENA)
	@${CP} -R ${WRKSRC}/missionpack ${DATADIR}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
