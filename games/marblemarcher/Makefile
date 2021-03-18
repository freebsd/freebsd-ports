# $FreeBSD$

PORTNAME=	marblemarcher
DISTVERSION=	1.4.5
CATEGORIES=	games

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Marble Marcher: Community Edition

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	glm>0:math/glm
LIB_DEPENDS=	libAntTweakBar.so:graphics/anttweakbar \
		libsfml-system.so:devel/sfml

USES=		cmake compiler:c++17-lang eigen:3 gl localbase:ldflags
USE_GL=		gl glew glu

USE_GITHUB=	yes
GH_ACCOUNT=	WAUthethird
GH_PROJECT=	Marble-Marcher-Community-Edition

CMAKE_ARGS=	-DFREEBSD_DATADIR=${DATADIR}

post-install:
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "cd ${DATADIR} && ./MarbleMarcher \"$$"@"\"" \
	) > ${STAGEDIR}${PREFIX}/bin/MarbleMarcher
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/MarbleMarcher

.include <bsd.port.mk>
