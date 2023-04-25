PORTNAME=	subsurface
DISTVERSIONPREFIX=v
DISTVERSION=	5.0.10
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Manage and display dive computer data
WWW=		https://subsurface-divelog.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdivecomputer.so:comms/libdc \
		libzip.so:archivers/libzip \
		libgit2.so:devel/libgit2 \
		libcurl.so:ftp/curl \
		libssh2.so:security/libssh2

USES=		cmake:noninja desktop-file-utils gmake pkgconfig qt:5 gnome qmake:no_configure sqlite
USE_GITHUB=	yes
GH_TUPLE=	subsurface:googlemaps:7ce7124b385b2ebac0f72c38b094f436d4fe5c58:subsurface/googlemaps
USE_GNOME=	libxml2 libxslt
USE_QT=		buildtools concurrent connectivity core declarative declarative-test:build gui linguisttools:build location network printsupport quickcontrols2 svg testlib webkit widgets

MAKE_ENV+=	DESTDIR=${STAGEDIR}

pre-configure:
	(cd ${WRKSRC}/googlemaps && ${QMAKE})

pre-build:
	(cd ${WRKSRC}/googlemaps && ${MAKE})

pre-install:
	(cd ${WRKSRC}/googlemaps && ${SETENV} INSTALL_ROOT=${STAGEDIR} make install)

post-build:
	${MV} ${WRKSRC}/Documentation/user-manual.html.git ${BUILD_WRKSRC}/Documentation/user-manual.html

dxo-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/subsurface ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/subsurface.desktop ${STAGEDIR}${PREFIX}/share/applications
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/icons/subsurface-icon.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "Documentation theme printing_templates translations" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
