# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openxcom
PORTVERSION=	0.9.0
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open-source reimplementation of the original X-Com

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	yaml-cpp:${PORTSDIR}/devel/yaml-cpp

USE_GITHUB=	yes
GH_ACCOUNT=	SupSuper
GH_PROJECT=	OpenXcom
GH_TAGNAME=	v0.9
GH_COMMIT=	5c8b540

USE_GMAKE=	yes
USE_SDL=	sdl mixer image gfx
USE_GL=		gl
MAKE_JOBS_SAFE=	yes
USE_GCC=	4.6+

BUILD_WRKSRC=	${WRKSRC}/src
MAKEFILE=	Makefile.simple

SUB_FILES=	pkg-message

PLIST_FILES=	bin/openxcom share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.svg
PLIST_DIRSTRY=	share/applications

PORTDOCS=	*
PORTDATA=	*

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/src/pch.h \
		${WRKSRC}/src/Engine/Surface.cpp
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/README.txt \
		${WRKSRC}/src/Engine/CrossPlatform.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin/
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/res/linux/openxcom.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/res/linux/icons/openxcom.svg ${PREFIX}/share/pixmaps
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/bin && ${COPYTREE_SHARE} data ${DATADIR}/
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}/
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
