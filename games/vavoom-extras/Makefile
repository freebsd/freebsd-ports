# New ports collection makefile for:	vavoom
# Date created:				2007-06-05
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	vavoom
PORTVERSION=	1.25
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/vmodels-doom/1.4.2:sf \
		http://doomtextures.freelanzer.com/:dt

PKGNAMESUFFIX=	-extras
DISTFILES=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Doom, Doom II, Heretic, Hexen and Strife source port (extras)

RUN_DEPENDS=	vavoom:${PORTSDIR}/games/vavoom

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_PACKAGE=	package will be 665MB; set FORCE_PACKAGE if you really want it

OPTIONS=	MODELS "Install 3D models (20MB)" on \
		SOUNDTRACKS "Install enhaced soundtracks (480MB)" on \
		TEXTURES "Install high resolution textures (165MB)" on

.include <bsd.port.pre.mk>

.if !defined(WITH_MODELS) && !defined(WITH_SOUNDTRACKS) && \
    !defined(WITH_TEXTURES)
IGNORE=		needs at least one option selected
.endif

.if defined(WITH_MODELS)
. for f in doom heretic hexen strife
DISTFILES+=	vmodels-${f}-1.4.2${EXTRACT_SUFX}:sf
. endfor
PLIST_SUB+=	MODELS=""
.else
PLIST_SUB+=	MODELS="@comment "
.endif

.if defined(WITH_TEXTURES)
DISTFILES+=	vv-dhtp-20071114.pk3:dt
. for f in heretic hexen strife
DISTFILES+=	vtextures-${f}-1.0${EXTRACT_SUFX}:sf
. endfor
PLIST_SUB+=	TEXTURES=""
.else
PLIST_SUB+=	TEXTURES="@comment "
.endif

.if defined(WITH_SOUNDTRACKS)
. for f in doom1 doom2 tnt plutonia heretic hexen
DISTFILES+=	vmusic-${f}-1.0${EXTRACT_SUFX}:sf
. endfor
PLIST_SUB+=	SOUNDTRACKS=""
.else
PLIST_SUB+=	SOUNDTRACKS="@comment "
.endif

post-extract:
	@${FIND} ${WRKSRC} -type f -name "*.txt" -delete

do-install:
	cd ${WRKSRC} && ${FIND} basev -type f \
		-exec ${INSTALL_DATA} {} ${DATADIR}/{} \;

.include <bsd.port.post.mk>
