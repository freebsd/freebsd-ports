PORTNAME=	coregarage
DISTVERSION=	4.5.0
CATEGORIES=	deskutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Settings manager for C Suite
WWW=		https://gitlab.com/cubocore/coregarage

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libarchiveqt5.so:archivers/libarchive-qt \
		libcprime-core.so:deskutils/libcprime

USES=		cmake desktop-file-utils localbase:ldflags qt:5
USE_QT=		buildtools:build core gui network qmake:build widgets
USE_GITLAB=	yes

GL_ACCOUNT=	CuboCore
GL_TAGNAME=	c03fd7d1bd37d4a11017cf242c55c66b157033fa

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
