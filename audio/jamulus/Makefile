# $FreeBSD$

PORTNAME=	jamulus
DISTVERSIONPREFIX=	r
DISTVERSION=	3_7_0
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Internet jam session software

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjack.so:audio/jack

USES=		compiler:c++11-lang gl pkgconfig qmake qt:5
USE_QT=		concurrent core gui network widgets xml buildtools_build linguisttools_build
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	jamulussoftware

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/jamulus.desktop \
		share/applications/jamulus-server.desktop \
		share/pixmaps/jamulus.png \
		share/pixmaps/jamulus-server.png

QMAKE_ARGS=	CONFIG+="noupcasename"

PORTSCOUT=	limit:^r\d+_ # prevent malformatted tags, like 'latest'

post-install:
		# workaround for https://gitlab.xfce.org/xfce/xfdesktop/-/issues/131
		${MV} ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/jamulus.png ${STAGEDIR}${PREFIX}/share/pixmaps/
		${RM} -r ${STAGEDIR}${PREFIX}/share/icons
		# add Jamulus Server menu item which is simply 'jamulus -s' with a special icon
		${CP} ${STAGEDIR}${PREFIX}/share/applications/jamulus.desktop ${STAGEDIR}${PREFIX}/share/applications/jamulus-server.desktop
		${REINPLACE_CMD} -i '' ' \
			s|Name=Jamulus|Name=Jamulus Server| ; \
			s|Comment=Jam Session|Comment=Jam Session Server| ; \
			s|Exec=jamulus|Exec=jamulus -s| ; \
			s|Icon=jamulus|Icon=jamulus-server| ; \
			' ${STAGEDIR}${PREFIX}/share/applications/jamulus-server.desktop
		${INSTALL_DATA} ${WRKSRC}/src/res/fronticonserver.png ${STAGEDIR}${PREFIX}/share/pixmaps/jamulus-server.png

.include <bsd.port.mk>
