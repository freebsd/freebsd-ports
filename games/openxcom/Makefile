# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openxcom
PORTVERSION=	0.9.0
PORTREVISION=	4
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open-source reimplementation of the original X-Com

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libyaml-cpp.so:${PORTSDIR}/devel/yaml-cpp

USE_GITHUB=	yes
GH_ACCOUNT=	SupSuper
GH_PROJECT=	OpenXcom
GH_TAGNAME=	v0.9
GH_COMMIT=	5c8b540

USES=		gmake pkgconfig
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

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/src/pch.h \
		${WRKSRC}/src/Engine/Surface.cpp
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/README.txt \
		${WRKSRC}/src/Engine/CrossPlatform.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/res/linux/openxcom.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/res/linux/icons/openxcom.svg ${STAGEDIR}${PREFIX}/share/pixmaps/
	cd ${WRKSRC}/bin && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
