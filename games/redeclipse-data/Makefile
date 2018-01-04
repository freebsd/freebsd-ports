# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redeclipse-data
PORTVERSION=	1.6.0
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Data files for Red Eclipse first-person shooter

USE_GITHUB=	nodefault
GH_TUPLE=	${DATAFILES:C/.*/red-eclipse:&:${DISTVERSIONPREFIX}${PORTVERSION}:&\/&/}

DATAFILES=	acerspyro actors appleflap blendbrush caustics crosshairs \
		decals dziq elyvisions fonts freezurbern john jojo jwin luckystrike \
		maps mayhem mikeplus64 misc nieb nobiax particles philipk \
		projectiles props skyboxes snipergoth sounds textures torley \
		trak ulukai unnamed vanities vegetation weapons wicked

NO_BUILD=	yes
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/redeclipse

PORTDATA=	*

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${DATAFILES}" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
