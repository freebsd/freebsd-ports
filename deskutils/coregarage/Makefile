PORTNAME=	coregarage
DISTVERSION=	4.3.0
PORTREVISION=	2
CATEGORIES=	deskutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Settings manager for C Suite

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libarchiveqt5.so:archivers/libarchive-qt \
		libcprime-core.so:deskutils/libcprime

USES=		cmake localbase:ldflags qt:5
USE_QT=		buildtools_build core gui network qmake_build widgets
USE_GITLAB=	yes

GL_ACCOUNT=	CuboCore
GL_COMMIT=	50d4c4f246a50df522c08e4b9af690a00ad96c1b

PLIST_FILES=	bin/coregarage \
		share/applications/org.cubocore.CoreGarage.desktop \
		share/icons/hicolor/scalable/apps/org.cubocore.CoreGarage.svg

pre-configure:
	@${REINPLACE_CMD} \
		-e 's|/usr/bin|${PREFIX}/bin|g' \
		-e 's|/usr/lib|${PREFIX}/lib|g' \
		-e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/coregarage.cpp \
		${WRKSRC}/coregarage.h \
		${WRKSRC}/org.cubocore.CoreGarage.desktop \
		${WRKSRC}/settings.cpp

.include <bsd.port.mk>
