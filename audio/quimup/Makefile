PORTNAME=	quimup
DISTVERSION=	2.1.1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/Quimup%20${DISTVERSION}
DISTNAME=	Quimup-${PORTVERSION}.source

MAINTAINER=	cmanv@duck.com
COMMENT=	Qt client for MPD (Music Player Daemon)
WWW=		https://sourceforge.net/projects/quimup/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient

USES=		compiler:c++17-lang gl pkgconfig qmake qt:6
USE_GL=		opengl
USE_QT=		base svg:run

CXXFLAGS+=	-std=c++17

DESKTOP_ENTRIES="Quimup" "MPD client" "quimup" "quimup" \
		"Audio;AudioVideo;Qt;" true
EXTRACT_AFTER_ARGS=	--exclude RPM_DEB_build \
			--exclude Release \
			--exclude Screenshots \
			--exclude changelog \
			--exclude readme \
			--no-same-owner --no-same-permissions

WRKSRC=		${WRKDIR}/Quimup-${DISTVERSION}.source

PLIST_FILES=	bin/quimup \
		share/pixmaps/quimup.svg

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/source/qm_mpdcom.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/quimup ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/source/resources/qm_main_icon.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps/quimup.svg

.include <bsd.port.mk>
