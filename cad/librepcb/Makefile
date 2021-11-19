PORTNAME=	librepcb
DISTVERSION=	0.1.6
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Schematic and PCB editing software

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++11-lang desktop-file-utils gl qt:5 shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	LibrePCB
GH_PROJECT=	LibrePCB
GH_TUPLE=	\
		LibrePCB:delaunay-triangulation:bd71456:delaunay_triangulation/libs/delaunay-triangulation \
		LibrePCB:dxflib:3b09713:dxflib/libs/dxflib \
		fontobene:fontobene-qt5:9b8c229:fontobene_qt5/libs/fontobene-qt5 \
		fontobene:fontobene-fonts:f197bc5:fontobene_fonts/share/librepcb/fontobene \
		LibrePCB:googletest:1e6322a:googletest/libs/googletest \
		LibrePCB:hoedown:600c3ee:hoedown/libs/hoedown \
		LibrePCB:muparser:2deb86a:muparser/libs/muparser \
		LibrePCB:optional:89d6d30:optional/libs/optional \
		LibrePCB:parseagle:ce0c8e6:parseagle/libs/parseagle \
		LibrePCB:quazip:dab1c52:quazip/libs/quazip \
		LibrePCB:type_safe:c3647fc:type_safe/libs/type_safe \
		LibrePCB:librepcb-test-data:dc902dc:librepcb_test_data/tests/data \
		LibrePCB:librepcb-fonts:c30f3b9:fonts/share/librepcb/fonts \
		LibrePCB:librepcb-i18n:efc96aa:i18n/i18n

USE_QT=		concurrent core gui network opengl printsupport sql svg xml widgets \
		buildtools_build linguisttools_build testlib_build qmake_build
USE_GL=		gl

post-install: # installs unnecessary headers: https://github.com/LibrePCB/LibrePCB/issues/935
	@${RMDIR} ${STAGEDIR}${DATADIR}/i18n

.include <bsd.port.mk>
