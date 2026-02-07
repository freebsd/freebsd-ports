PORTNAME=	nevada-toolset
PORTVERSION=	g20200815
CATEGORIES=	archivers games

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Tools for working with old Westwood game data formats
WWW=		https://github.com/TheAssemblyArmada/NevadaToolset

LICENSE=	GPLv2+

USES=		cmake
USE_GITHUB=	yes

GH_ACCOUNT=	TheAssemblyArmada
GH_PROJECT=	NevadaToolset BaseConfig:bc CaptainsLog:cl
GH_TAGNAME=	d1ef341 a98fc2c:bc 6a52d80:cl
GH_SUBDIR=	libs/baseconfig:bc libs/captainslog:cl

PLIST_FILES=	bin/makemix bin/strgen bin/unmakemix

do-install:
	${INSTALL_PROGRAM} \
		${PLIST_FILES:[1..3]:S,bin,${INSTALL_WRKSRC}/src,} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
