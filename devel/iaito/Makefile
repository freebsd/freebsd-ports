PORTNAME=	iaito
DISTVERSION=	5.9.2
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Official QT frontend of radare2, a libre reverse engineering framework
WWW=		https://github.com/radareorg/iaito

LICENSE=	GPLv3

LIB_DEPENDS=	libcapstone.so:devel/capstone \
		libr_core.so:devel/radare2

USES=		desktop-file-utils gl gmake pkgconfig qmake:no_configure qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	radareorg
USE_GL=		gl
USE_QT=		buildtools core gui linguisttools:build network svg widgets
GNU_CONFIGURE=	yes
MAKE_ENV=	DESTDIR=${STAGEDIR}${PREFIX} \
		QMAKE_FLAGS="PREFIX=${STAGEDIR}${PREFIX}"

PLIST_FILES=	bin/iaito \
		share/applications/org.radare.iaito.desktop \
		share/icons/hicolor/scalable/apps/org.radare.iaito.svg \
		share/metainfo/org.radare.iaito.appdata.xml

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/org.radare.iaito.desktop \
			${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/src/img/org.radare.iaito.svg \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/src/org.radare.iaito.appdata.xml \
			${STAGEDIR}${PREFIX}/share/metainfo

.include <bsd.port.mk>
