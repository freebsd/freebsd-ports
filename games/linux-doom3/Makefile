# Created by: alepulver
# $FreeBSD$

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

OPTIONS_DEFINE=	NO_CDKEY
NO_CDKEY_DESC=	Use older version which doesn't require cd key

DATADIR=	${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
SUB_FILES=	doom3 doom3-ded pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNO_CDKEY}
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

.if empty(PORT_OPTIONS:MNO_CDKEY)
post-extract:
	@${RM} ${WRKSRC}/pb/PB_EULA.txt
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/base
	cd ${WRKSRC}/base && \
		${INSTALL_DATA} game01.pk4 pak*.pk4 ${STAGEDIR}${DATADIR}/base
	cd ${WRKSRC}/bin/Linux/x86 && \
		${INSTALL_PROGRAM} doom.x86 doomded.x86 ${STAGEDIR}${DATADIR}
.if empty(PORT_OPTIONS:MNO_CDKEY)
	@${MKDIR} ${STAGEDIR}${DATADIR}/d3xp
	cd ${WRKSRC}/d3xp && \
		${INSTALL_DATA} game01.pk4 pak*.pk4 ${STAGEDIR}${DATADIR}/d3xp
	${CP} -r ${WRKSRC}/pb ${STAGEDIR}${DATADIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/doom3.png ${STAGEDIR}${PREFIX}/share/pixmaps
.for f in doom3 doom3-ded
	${INSTALL_PROGRAM} ${WRKDIR}/${f} ${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}${f}
.endfor

.include <bsd.port.mk>
