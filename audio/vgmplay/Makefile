PORTNAME=	vgmplay
PORTVERSION=	0.51.1
CATEGORIES=	audio

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Command-line player for VGM (video game music) files
WWW=		https://vgmrips.net/

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/vgm-player.pc:audio/libvgm
LIB_DEPENDS=	libinih.so:devel/inih

USES=		cmake iconv pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	ValleyBell
GH_PROJECT=	${PORTNAME}-libvgm

PLIST_FILES=	bin/vgmplay \
		${EXAMPLESDIR}/vgmplay.ini

OPTIONS_DEFINE=		MEDIACONTROLS
OPTIONS_DEFAULT=	# none

MEDIACONTROLS_DESC=	Media Controls via D-Bus

MEDIACONTROLS_CMAKE_ON=	-DMEDIA_CONTROLS:STRING="DBUS"
MEDIACONTROLS_CMAKE_OFF=-DMEDIA_CONTROLS:STRING="OFF"
MEDIACONTROLS_LIB_DEPENDS=	libdbus-1.so:devel/dbus

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/main.cpp

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/VGMPlay.ini ${STAGEDIR}${EXAMPLESDIR}/vgmplay.ini

.include <bsd.port.mk>
