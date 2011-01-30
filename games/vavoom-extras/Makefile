# New ports collection makefile for:	vavoom
# Date created:				2007-06-05
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	vavoom-extras
PORTVERSION=	1.30
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/vavoom/Resources/vmodels-doom/1.4.3:vmd \
		SF/vavoom/Resources/vmodels-heretic/1.4.3:vmhr \
		SF/vavoom/Resources/vmodels-hexen/1.4.3:vmhx \
		SF/vavoom/Resources/vmodels-strife/1.4.3:vms \
		SF/vavoom/Resources/vmusic/1.0:vmu \
		SF/vavoom/Resources/vtextures/1.0:vt10 \
		SF/vavoom/Resources/vtextures/1.1:vt11 \
		http://doomtextures.freelanzer.com/:dt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Doom, Doom II, Heretic, Hexen and Strife source port (extras)

RUN_DEPENDS=	vavoom:${PORTSDIR}/games/vavoom

DATADIR=	${PREFIX}/share/vavoom

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_PACKAGE=	package could be up to 661MB; set FORCE_PACKAGE if you really want it

OPTIONS=	MODELS "Install 3D models (17MB)" on \
		SOUNDTRACKS "Install enhaced soundtracks (482MB)" on \
		TEXTURES "Install high resolution textures (157MB)" on \
		DHTP "Prefer Doom Hires Texture Pack (87MB)" off

.include <bsd.port.pre.mk>

.if !defined(WITH_MODELS) && !defined(WITH_SOUNDTRACKS) && !defined(WITH_TEXTURES) && !defined(WITH_DHTP)
IGNORE=		needs at least one option selected
.endif

.if defined(WITH_MODELS)
DISTFILES+=	vmodels-doom-1.4.3.zip:vmd
DISTFILES+=	vmodels-heretic-1.4.3.zip:vmhr
DISTFILES+=	vmodels-hexen-1.4.3.zip:vmhx
DISTFILES+=	vmodels-strife-1.4.3.zip:vms
PLIST_SUB+=	MODELS=""
.else
PLIST_SUB+=	MODELS="@comment "
.endif

.if defined(WITH_DHTP)
DISTFILES+=	vv-dhtp-20080808.pk3:dt
PLIST_SUB+=	DHTP=""
.else
PLIST_SUB+=	DHTP="@comment "
.endif

.if defined(WITH_TEXTURES)
. for f in heretic hexen strife
DISTFILES+=	vtextures-${f}-1.0${EXTRACT_SUFX}:vt10
. endfor
PLIST_SUB+=	TEXTURES=""
.else
PLIST_SUB+=	TEXTURES="@comment "
.endif

.if defined(WITH_TEXTURES) && !defined(WITH_DHTP)
. for f in plutonia tnt
DISTFILES+=	vtextures-${f}-1.0${EXTRACT_SUFX}:vt10
. endfor
. for f in doom doom1 doom2
DISTFILES+=	vtextures-${f}-1.1${EXTRACT_SUFX}:vt11
. endfor
PLIST_SUB+=	NODHTP=""
.else
PLIST_SUB+=	NODHTP="@comment "
.endif

.if defined(WITH_SOUNDTRACKS)
. for f in doom1 doom2 tnt plutonia heretic hexen
DISTFILES+=	vmusic-${f}-1.0${EXTRACT_SUFX}:vmu
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
