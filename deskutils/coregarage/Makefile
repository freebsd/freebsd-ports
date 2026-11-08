PORTNAME=	coregarage
DISTVERSION=	5.0.1
CATEGORIES=	deskutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Settings manager for C Suite
WWW=		https://gitlab.com/cubocore/coregarage

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcprime-core.so:deskutils/libcprime

USES=		cmake desktop-file-utils gl localbase:ldflags qt:6
USE_GL=		gl opengl
USE_QT=		base tools:build
USE_GITLAB=	yes

GL_ACCOUNT=	CuboCore
GL_TAGNAME=	v${DISTVERSION}

PLIST_FILES=	bin/coregarage \
		share/applications/cc.cubocore.CoreGarage.desktop \
		share/icons/hicolor/scalable/apps/cc.cubocore.CoreGarage.svg \
		share/metainfo/cc.cubocore.CoreGarage.metainfo.xml

pre-configure:
	@${REINPLACE_CMD} \
		-e 's|/usr/bin|${PREFIX}/bin|g' \
		-e 's|/usr/lib|${PREFIX}/lib|g' \
		-e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/src/coregarage.cpp \
		${WRKSRC}/src/settings.cpp \
		${WRKSRC}/src/coregarage.h \
		${WRKSRC}/cc.cubocore.CoreGarage.desktop

.include <bsd.port.mk>
