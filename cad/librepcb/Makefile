# $FreeBSD$

PORTNAME=	librepcb
DISTVERSION=	0.1.4
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Schematic and PCB editing software

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c++11-lang desktop-file-utils gl qmake qt:5 shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	LibrePCB
GH_PROJECT=	LibrePCB
GH_TUPLE=	\
		LibrePCB:hoedown:dae7992:hoedown/libs/hoedown \
		LibrePCB:quazip:e13d52b:quazip/libs/quazip \
		LibrePCB:googletest:2a26840:googletest/libs/googletest \
		LibrePCB:librepcb-test-data:c1912fd5c2123d5e530da7784381ec8a7fca23ad:LibrePCB_librepcb_test_data/tests/data \
		LibrePCB:parseagle:87d9da6:parseagle/libs/parseagle \
		LibrePCB:sexpresso:5020552:sexpresso/libs/sexpresso \
		fontobene:fontobene-qt5:f167099:fontobene_lib/libs/fontobene \
		LibrePCB:fontobene-fonts:f197bc5:fontobene_share/share/librepcb/fontobene \
		LibrePCB:delaunay-triangulation:bd71456:delaunay_triangulation/libs/delaunay-triangulation \
		LibrePCB:librepcb-fonts:c30f3b9:librepcb_fonts/share/librepcb/fonts \
		LibrePCB:optional:89d6d30:optional/libs/optional \
		LibrePCB:type_safe:206f0db:type_safe/libs/type_safe \
		LibrePCB:librepcb-i18n:efc96aa:i18n/i18n \
		LibrePCB:muparser:28a90191aa80889e29d80d5c0ab842b2bcd1ba95:LibrePCB_muparser/libs/muparser \
		foonathan:debug_assert:130adcb:debug_assert/libs/type_safe/external/debug_assert
USE_QT=		concurrent core gui network opengl printsupport sql svg xml widgets buildtools_build testlib_build
USE_GL=		gl

.include <bsd.port.mk>
