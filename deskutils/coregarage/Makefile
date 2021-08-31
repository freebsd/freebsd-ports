PORTNAME=	coregarage
DISTVERSION=	4.3.0
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Settings manager for C Suite

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libarchiveqt5.so:archivers/libarchive-qt \
		libcprime-core.so:deskutils/libcprime

USES=		cmake localbase:ldflags qt:5
USE_QT=		buildtools_build core gui qmake_build widgets
USE_GITLAB=	yes

GL_ACCOUNT=	CuboCore
GL_COMMIT=	684e579b4a03914b77ceccd6efcfc490c53ad730

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
