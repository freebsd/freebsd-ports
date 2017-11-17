# $FreeBSD$

PORTNAME=	abGate
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.9
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Noise gate LV2 plugin

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	antanasbruzas
USE_CXXSTD=	c++11
USE_QT4=	corelib gui moc_build rcc_build qmake_build uic_build
USE_GNOME=	atkmm gtk20 gtkmm24 libsigc++20
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e ' \
		s|PREFIX = |PREFIX ?= |; \
		s|g++|$$(CXX)|; \
		s|CPPFLAGS|CXXFLAGS|; \
		s| -g -O3||; \
		s|cd abGateQt; qmake; make|cd abGateQt; qmake \&\& $$(MAKE)|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E ' \
		s|^QMAKE_CXXFLAGS (.*)|QMAKE_CXXFLAGS = ${CXXFLAGS}|; \
		s|^QMAKE_LFLAGS (.*)|QMAKE_LFLAGS = ${LDFLAGS}|' \
		${WRKSRC}/abGateQt/abGateQt.pro

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/abGate.lv2/*.so

.include <bsd.port.mk>
