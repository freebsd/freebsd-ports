PORTNAME=	3d-ascii-viewer
PORTVERSION=	1.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Viewer of 3D models in ASCII
WWW=		https://github.com/autopawn/3d-ascii-viewer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	autopawn

ALL_TARGET=	3d-ascii-viewer

PLIST_FILES=	bin/3d-ascii-viewer
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/3d-ascii-viewer ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/models
	${INSTALL_DATA} ${WRKSRC}/models/* ${STAGEDIR}${EXAMPLESDIR}/models/

.include <bsd.port.mk>
