# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	milton
PORTVERSION=	1.9.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Infinite-canvas paint program

LICENSE=	GPLv3+

BUILD_DEPENDS=	icotool:graphics/icoutils

USE_GITHUB=	yes
GH_ACCOUNT=	serge-rgb

USES=		cmake compiler:c++11-lang gl gnome sdl xorg
USE_GL=		gl glu
USE_GNOME=	cairo gtk20
USE_SDL=	sdl2 image2
USE_XORG=	ice sm x11 xext xi
INSTALLS_ICONS=	yes

PLIST_FILES=	bin/milton ${DATADIR_REL}/Carlito.ttf
.for n in 16 32 48 64 128 256
PLIST_FILES+=	share/icons/hicolor/${n}x${n}/apps/milton.png
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's:__linux__:__${OPSYS}__:' \
		${WRKSRC}/src/easytab.h
	@${REINPLACE_CMD} -e 's:Carlito\.ttf:${DATADIR}/&:' \
		${WRKSRC}/src/sdl_milton.cc
	@${REINPLACE_CMD} -e 's:milton\.png:${PREFIX}/share/icons/hicolor/256x256/apps/&:' \
		${WRKSRC}/src/platform_linux.cc
	@${REINPLACE_CMD} -E '/case (ENODATA|ENOST?R|ETIME):/d' \
		${WRKSRC}/src/shadergen.cc

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/Milton \
		${STAGEDIR}${PREFIX}/bin/milton
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/third_party/Carlito.ttf \
		${STAGEDIR}${DATADIR}
.for n in 16 32 48 64 128 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${n}x${n}/apps
	${INSTALL_DATA} ${INSTALL_WRKSRC}/milton_icon_?_${n}x${n}x32.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${n}x${n}/apps/milton.png
.endfor

.include <bsd.port.mk>
