# $FreeBSD$

PORTNAME=	Drawpile
DISTVERSION=	2.0.9
CATEGORIES=	graphics python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collaborative drawing program

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgif.so:graphics/giflib \
		libmicrohttpd.so:www/libmicrohttpd \
		libminiupnpc.so:net/miniupnpc \
		libsodium.so:security/libsodium

USES=		cmake:outsource desktop-file-utils kde:5 pkgconfig shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tl}
USE_QT5=	core gui multimedia network sql svg widgets buildtools_build linguisttools_build qmake_build
USE_KDE=	archive

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:tl}
PLIST_SUB=	PORTVERSION=${PORTVERSION}

post-install:
.for SZ in 16 32 64 128 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}x${SZ}/apps ${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}x${SZ}/mimetypes
	${INSTALL_DATA} ${WRKSRC}/desktop/drawpile-${SZ}x${SZ}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}x${SZ}/apps/drawpile.png
	${INSTALL_DATA} ${WRKSRC}/desktop/drawpile-${SZ}x${SZ}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}x${SZ}/mimetypes/application-x-drawpile-recording.png
	${INSTALL_DATA} ${WRKSRC}/desktop/drawpile-${SZ}x${SZ}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}x${SZ}/mimetypes/gnome-mime-application-x-drawpile-recording.png
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKSRC}/desktop/x-drawpile.xml ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKSRC}/desktop/drawpile.desktop ${STAGEDIR}${PREFIX}/share/applications
	@${RM} ${STAGEDIR}${DOCSDIR}/COPYING

.include <bsd.port.mk>
