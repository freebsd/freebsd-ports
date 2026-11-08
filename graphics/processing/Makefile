PORTNAME=	processing
PORTVERSION=	4.5.6
PORTEPOCH=	1
CATEGORIES=	graphics linux
MASTER_SITES=	https://github.com/processing/processing4/releases/download/processing-1434-${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux-x64-portable
EXTRACT_SUFX=	.zip

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Programming environment for images, animation, and interactions
WWW=		https://processing.org/

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64

USES=		desktop-file-utils linux:rl9 zip
USE_LINUX=	dri fontconfig xorglibs

WRKSRC=		${WRKDIR}/Processing
NO_BUILD=	yes

SUB_FILES=	processing pkg-message

post-extract:
# The bundled JDK's source bundle is only useful for source attachment
# in external IDEs and is not referenced by Processing.
	@${RM} ${WRKSRC}/lib/app/resources/jdk/src.zip \
		${WRKSRC}/lib/app/resources/jdk/lib/src.zip

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/processing
	${CP} -Rp ${WRKSRC}/bin ${STAGEDIR}${PREFIX}/libexec/processing
	${CP} -Rp ${WRKSRC}/lib ${STAGEDIR}${PREFIX}/libexec/processing
	${INSTALL_SCRIPT} ${WRKDIR}/processing ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/applications \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/1024x1024/apps
	${INSTALL_DATA} ${FILESDIR}/processing.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/lib/Processing.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/1024x1024/apps/processing.png

.include <bsd.port.mk>
