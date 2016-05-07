# Created by: alepulver
# $FreeBSD$

PORTNAME=	vavoom-extras
PORTVERSION=	1.30
PORTREVISION=	3
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

LICENSE=	GPLv2

RUN_DEPENDS=	vavoom:games/vavoom

DATADIR=	${PREFIX}/share/vavoom

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
LEGAL_PACKAGE=	package could be up to 655MB; set FORCE_PACKAGE if you really want it
NO_PACKAGE=	${LEGAL_PACKAGE}

OPTIONS_MULTI=	EXTRA
OPTIONS_MULTI_EXTRA=	MODELS SOUNDTRACKS TEXTURES
OPTIONS_DEFAULT=	MODELS

MODELS_DESC=	Install 3D models (17MB)
SOUNDTRACKS_DESC=	Install enhanced soundtracks (482MB)
TEXTURES_DESC=	Install high resolution textures (157MB)

MODELS_DISTFILES+=	vmodels-doom-1.4.3${EXTRACT_SUFX}:vmd \
			vmodels-heretic-1.4.3${EXTRACT_SUFX}:vmhr \
			vmodels-hexen-1.4.3${EXTRACT_SUFX}:vmhx \
			vmodels-strife-1.4.3${EXTRACT_SUFX}:vms

.for f in doom doom1 doom2
TEXTURES_DISTFILES+=	vtextures-${f}-1.1${EXTRACT_SUFX}:vt11
.endfor

.for f in heretic hexen plutonia strife tnt
TEXTURES_DISTFILES+=	vtextures-${f}-1.0${EXTRACT_SUFX}:vt10
.endfor

.for f in doom1 doom2 heretic hexen tnt plutonia
SOUNDTRACKS_DISTFILES+=	vmusic-${f}-1.0${EXTRACT_SUFX}:vmu
.endfor

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

post-extract:
	@${FIND} ${WRKSRC} -type f -name "*.txt" -delete

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} basev ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
