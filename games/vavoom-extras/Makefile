# Created by: alepulver
# $FreeBSD$

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
		SF/vavoom/Resources/vtextures/1.1:vt11

MAINTAINER=	bar@FreeBSD.org
COMMENT=	Doom, Doom II, Heretic, Hexen, and Strife source port (extras)

RUN_DEPENDS=	vavoom:${PORTSDIR}/games/vavoom

DATADIR=	${PREFIX}/share/vavoom

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_PACKAGE=	package could be up to 655MB; set FORCE_PACKAGE if you really want it

OPTIONS_MULTI=	EXTRA
OPTIONS_MULTI_EXTRA=	MODELS SOUNDTRACKS TEXTURES
OPTIONS_DEFAULT=	MODELS

MODELS_DESC=	Install 3D models (17MB)
SOUNDTRACKS_DESC=	Install enhanced soundtracks (482MB)
TEXTURES_DESC=	Install high resolution textures (157MB)

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMODELS}
DISTFILES+=	vmodels-doom-1.4.3.zip:vmd
DISTFILES+=	vmodels-heretic-1.4.3.zip:vmhr
DISTFILES+=	vmodels-hexen-1.4.3.zip:vmhx
DISTFILES+=	vmodels-strife-1.4.3.zip:vms
PLIST_SUB+=	MODELS=""
.else
PLIST_SUB+=	MODELS="@comment "
.endif

.if ${PORT_OPTIONS:MTEXTURES}
. for f in doom doom1 doom2
DISTFILES+=	vtextures-${f}-1.1${EXTRACT_SUFX}:vt11
. endfor
. for f in heretic hexen plutonia strife tnt
DISTFILES+=	vtextures-${f}-1.0${EXTRACT_SUFX}:vt10
. endfor
PLIST_SUB+=	TEXTURES=""
.else
PLIST_SUB+=	TEXTURES="@comment "
.endif

.if ${PORT_OPTIONS:MSOUNDTRACKS}
. for f in doom1 doom2 heretic hexen tnt plutonia
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

.include <bsd.port.mk>
