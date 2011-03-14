# New ports collection makefile for:	quake2-extras
# Date created:				27 Jul 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	extras
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org/quake2/files/:retex \
		http://www.icculus.org/quake2/files/:retex \
		http://www-personal.umich.edu/~jimw/q2/files/:retex2
PKGNAMEPREFIX=	${Q2PKGNAMEPREFIX}
DISTFILES=	#
DIST_SUBDIR=	${LATEST_LINK}
EXTRACT_ONLY=	#

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake II extras (high quality textures and skins)

USE_ZIP=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	RETEXTURE "Install high quality textures" on \
		RETEXTURE_FULL "Install more textures (120MB)" off \
		SKINS "Install high quality skins" off

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}

RETEX_PAKS=	10 11 12 13 14 16 17 19
RETEX_FULL=	all_q2_textures_07_17_2006.zip
SKINS=		models.zip

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITH_RETEXTURE_FULL) || defined(WITH_SKINS)
BUILD_DEPENDS+=	nwreckdum:${PORTSDIR}/archivers/nwreckdum
PLIST_FILES+=	%%Q2DIR%%/baseq2/pak20.pak
.endif

.if defined(WITH_RETEXTURE) && !defined(WITH_RETEXTURE_FULL)
.for i in ${RETEX_PAKS}
DISTFILES+=	pak${i}.pak:retex
PLIST_FILES+=	%%Q2DIR%%/baseq2/pak${i}.pak
.endfor
PLIST_SUB+=	RETEX=""
.else
PLIST_SUB+=	RETEX="@comment "
.endif

.if defined(WITH_RETEXTURE_FULL)
DISTFILES+=	${RETEX_FULL}:retex2
EXTRACT_ONLY+=	${RETEX_FULL}
PLIST_FILES+=	%%Q2DIR%%/baseq2/pak10.pak
.endif

.if defined(WITH_SKINS)
DISTFILES+=	${SKINS}:retex2
EXTRACT_ONLY+=	${SKINS}
PLIST_FILES+=	%%Q2DIR%%/baseq2/pak20.pak
.endif

post-extract:
.if defined(WITH_RETEXTURE_FULL)
	@${MKDIR} ${WRKSRC}/pak10
	@${MV} ${WRKSRC}/textures ${WRKSRC}/pak10
.endif
.if defined(WITH_SKINS)
	@${MKDIR} ${WRKSRC}/pak20
	@${MV} ${WRKSRC}/models ${WRKSRC}/pak20
.endif

do-build:
.if defined(WITH_RETEXTURE_FULL)
	@nwreckdum -c -p ${WRKSRC}/pak10.pak -d ${WRKSRC}/pak10
.endif
.if defined(WITH_SKINS)
	@nwreckdum -c -p ${WRKSRC}/pak20.pak -d ${WRKSRC}/pak20
.endif

do-install:
.if defined(WITH_RETEXTURE) && !defined(WITH_RETEXTURE_FULL)
.for i in ${RETEX_PAKS}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/pak${i}.pak ${Q2DIR}/baseq2
.endfor
.endif
.if defined(WITH_RETEXTURE_FULL)
	${INSTALL_DATA} ${WRKSRC}/pak10.pak ${Q2DIR}/baseq2
.endif
.if defined(WITH_SKINS)
	${INSTALL_DATA} ${WRKSRC}/pak20.pak ${Q2DIR}/baseq2
.endif

.include <bsd.port.post.mk>
