# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	extras
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org/quake2/files/:retex \
		http://www.icculus.org/quake2/files/:retex \
		http://www-personal.umich.edu/~jimw/q2/files/:retex2 \
		http://www-personal.umich.edu/~jimw/q2/aq2_install/:models
PKGNAMEPREFIX=	${Q2PKGNAMEPREFIX}
DISTFILES=	#
DIST_SUBDIR=	${PKGBASE}
EXTRACT_ONLY=	#

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake II extras (high quality textures and skins)

USES=		zip
NO_WRKSUBDIR=	yes

RETEX_PAKS=	10 11 12 13 14 16 17 19
RETEX_FULL=	all_q2_textures_07_17_2006zip
SKINS=		models.zip

OPTIONS_DEFINE=	RETEXTURE RETEXTURE_FULL SKINS
OPTIONS_DEFAULT=	RETEXTURE

RETEXTURE_DESC=		Install high quality textures
RETEXTURE_FULL_DESC=	Install more textures (120MB)
SKINS_DESC=		Install high quality skins

.include "${.CURDIR}/../quake2-data/Makefile.include"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRETEXTURE_FULL} || ${PORT_OPTIONS:MSKINS}
BUILD_DEPENDS+=	nwreckdum:archivers/nwreckdum
PLIST_FILES+=	%%Q2DIR%%/baseq2/pak20.pak
.endif

.if ${PORT_OPTIONS:MRETEXTURE} && ! ${PORT_OPTIONS:MRETEXTURE_FULL}
.for i in ${RETEX_PAKS}
DISTFILES+=	pak${i}.pak:retex
PLIST_FILES+=	%%Q2DIR%%/baseq2/pak${i}.pak
.endfor
PLIST_SUB+=	RETEX=""
.else
PLIST_SUB+=	RETEX="@comment "
.endif

.if ${PORT_OPTIONS:MRETEXTURE_FULL}
DISTFILES+=	${RETEX_FULL}:retex2
EXTRACT_ONLY+=	${RETEX_FULL}
PLIST_FILES+=	%%Q2DIR%%/baseq2/pak10.pak
.endif

.if ${PORT_OPTIONS:MSKINS}
DISTFILES+=	${SKINS}:models
EXTRACT_ONLY+=	${SKINS}
PLIST_FILES+=	%%Q2DIR%%/baseq2/pak20.pak
.endif

post-extract:
.if ${PORT_OPTIONS:MRETEXTURE_FULL}
	@${MKDIR} ${WRKSRC}/pak10
	@${MV} ${WRKSRC}/textures ${WRKSRC}/pak10
.endif
.if ${PORT_OPTIONS:MSKINS}
	@${MKDIR} ${WRKSRC}/pak20
	@${MV} ${WRKSRC}/models ${WRKSRC}/pak20
.endif

do-build:
.if ${PORT_OPTIONS:MRETEXTURE_FULL}
	@nwreckdum -c -p ${WRKSRC}/pak10.pak -d ${WRKSRC}/pak10
.endif
.if ${PORT_OPTIONS:MSKINS}
	@nwreckdum -c -p ${WRKSRC}/pak20.pak -d ${WRKSRC}/pak20
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${Q2DIR}/baseq2
.if ${PORT_OPTIONS:MRETEXTURE} && empty(PORT_OPTIONS:MRETEXTURE_FULL)
.  for i in ${RETEX_PAKS}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/pak${i}.pak \
		${STAGEDIR}${Q2DIR}/baseq2
.  endfor
.endif
.if ${PORT_OPTIONS:MRETEXTURE_FULL}
	${INSTALL_DATA} ${WRKSRC}/pak10.pak ${STAGEDIR}${Q2DIR}/baseq2
.endif
.if ${PORT_OPTIONS:MSKINS}
	${INSTALL_DATA} ${WRKSRC}/pak20.pak ${STAGEDIR}${Q2DIR}/baseq2
.endif

.include <bsd.port.mk>
