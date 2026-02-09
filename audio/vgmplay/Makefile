PORTNAME=	vgmplay
PORTVERSION=	0.52.0
CATEGORIES=	audio

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Command-line player for VGM (video game music) files
WWW=		https://vgmrips.net/

LIB_DEPENDS=	libvgm-emu.so:audio/libvgm \
		libinih.so:devel/inih

USES=		cmake iconv pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	ValleyBell
GH_PROJECT=	${PORTNAME}-libvgm

PLIST_FILES=	bin/vgmplay \
		${EXAMPLESDIR}/vgmplay.ini
PORTDOCS=	Updates.txt VGMPlay.txt

OPTIONS_DEFINE=		DOCS MEDIACONTROLS
OPTIONS_DEFAULT=	# none

MEDIACONTROLS_DESC=	Media Controls via D-Bus

MEDIACONTROLS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
MEDIACONTROLS_CMAKE_ON=	-DMEDIA_CONTROLS:STRING="DBUS"
MEDIACONTROLS_CMAKE_OFF=-DMEDIA_CONTROLS:STRING="OFF"

post-install:
.for f in updates.txt vgmplay.ini vgmplay.txt
	@${RM} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/VGMPlay.ini ${STAGEDIR}${EXAMPLESDIR}/vgmplay.ini

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
