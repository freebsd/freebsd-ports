# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openxcom
PORTVERSION=	1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	7
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open-source reimplementation of the original X-Com

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libyaml-cpp.so:devel/yaml-cpp

BROKEN_powerpc64=	fails to compile: XcomResourcePack.cpp: undefined reference to YAML::LoadFile

USE_GITHUB=	yes
GH_ACCOUNT=	SupSuper
GH_PROJECT=	OpenXcom

USES=		compiler:c++11-lang gmake pkgconfig
USE_CXXSTD=	c++11
USE_SDL=	sdl mixer image gfx
USE_GL=		gl

BUILD_WRKSRC=	${WRKSRC}/src
MAKEFILE=	Makefile.simple

SUB_FILES=	pkg-message

PLIST_FILES=	bin/openxcom share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.svg

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/README.txt \
		${WRKSRC}/src/Engine/CrossPlatform.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/res/linux/openxcom.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/res/linux/icons/openxcom.svg ${STAGEDIR}${PREFIX}/share/pixmaps/
	@cd ${WRKSRC}/bin && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${WRKSRC}/CHANGELOG.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
