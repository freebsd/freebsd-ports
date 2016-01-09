# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redeclipse-data
PORTVERSION=	1.5.3
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Data files for Red Eclipse first-person shooter

MANUAL_PACKAGE_BUILD=	huge (742MiB)

USE_GITHUB=	yes
GH_ACCOUNT=	red-eclipse
# acerpyro is duplicated as there's no way to not use default GH group
GH_PROJECT=	acerspyro ${DATAFILES:C/.*/&:&/}

DATAFILES=	acerspyro actors appleflap blendbrush caustics crosshairs \
		elyvisions fonts freezurbern john jojo jwin luckystrike \
		maps mayhem mikeplus64 misc nobiax particles philipk \
		projectiles props skyboxes sounds textures torley trak \
		ulukai unnamed vanities vegetation weapons wicked

NO_BUILD=	yes
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/redeclipse

PORTDATA=	*

post-extract:
.for f in ${DATAFILES}
	@${MV} ${WRKDIR}/${f}-${PORTVERSION} ${WRKDIR}/${f}
.endfor

do-install:
	cd ${WRKDIR} && ${COPYTREE_SHARE} "${DATAFILES}" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
