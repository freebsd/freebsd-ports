PORTNAME=	vamos
PORTVERSION=	0.8.2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automotive simulation framework
WWW=		https://vamos.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR}
LIB_DEPENDS=	${PY_BOOST} \
		libpng.so:graphics/png

USES=		compiler:c++11-lang gl libtool localbase openal:al,alut \
		python sdl xorg
USE_XORG=	sm ice x11 xi xext xmu
USE_GL=		gl glu glut
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-unit-tests=no
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
LLD_UNSAFE=	for preemption of audio/openal-soft libs

INFO=		vamos
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

ICON_SIZES=	32x32 48x48 64x64 72x72 96x96 128x128

DESKTOP_ENTRIES="Vamos" "" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} -e '/test/s,ax_boost_python_lib",BOOST_PYTHON_LIB",' \
	    -e 's,^for python in python.*python;,for python in python${PYTHON_VER};,' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/std::/s,mem_fun,mem_fn,' \
		${WRKSRC}/body/Gl_Car.cc \
		${WRKSRC}/track/Strip_Track.cc

post-install:
.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ../icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	cd ${WRKSRC} && ${COPYTREE_SHARE} "AUTHORS ChangeLog README TODO doc/matrixfaq.htm" \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
