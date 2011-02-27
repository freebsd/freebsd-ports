# New ports collection makefile for:	linux-doom3
# Date created:				7 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	doom3
PORTVERSION=	1.3.1.1304
PORTEPOCH=	1
CATEGORIES=	games linux
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE}
MASTER_SITE_SUBDIR=	doom3/linux
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-linux-${PORTVERSION}.x86
EXTRACT_SUFX=	.run

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Doom III for Linux

USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
NO_CDROM=	Redistribution is limited, see license
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	NO_CDKEY "Use older version which doesn't require cd key" off

DATADIR=	${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
SUB_FILES=	doom3 doom3-ded pkg-message

.include <bsd.port.pre.mk>

.if defined(WITH_NO_CDKEY)
MASTER_SITE_SUBDIR=	doom3/linux/old
PORTVERSION=	1.1.1286
PORTEPOCH=	0
PLIST_SUB+=	NEW="@comment "
.else
PLIST_SUB+=	NEW=""
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && ${TAIL} +374 ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} zxf -

.if !defined(WITH_NO_CDKEY)
post-extract:
	@${RM} ${WRKSRC}/pb/PB_EULA.txt
.endif

do-install:
	${MKDIR} ${DATADIR}/base
	cd ${WRKSRC}/base && \
		${INSTALL_DATA} game01.pk4 pak*.pk4 ${DATADIR}/base
	cd ${WRKSRC}/bin/Linux/x86 && \
		${INSTALL_PROGRAM} doom.x86 doomded.x86 ${DATADIR}
.if !defined(WITH_NO_CDKEY)
	${MKDIR} ${DATADIR}/d3xp
	cd ${WRKSRC}/d3xp && \
		${INSTALL_DATA} game01.pk4 pak*.pk4 ${DATADIR}/d3xp
	${CP} -r ${WRKSRC}/pb ${DATADIR}
.endif
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/doom3.png ${PREFIX}/share/pixmaps
.for f in doom3 doom3-ded
	${INSTALL_PROGRAM} ${WRKDIR}/${f} ${PREFIX}/bin/${PKGNAMEPREFIX}${f}
.endfor

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
