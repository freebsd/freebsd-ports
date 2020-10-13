# $FreeBSD$

PORTNAME=	abGate
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.9
PORTREVISION=	3
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	fbe77164cf58807807b8c6ec496430f34f88d780.patch:-p1 # Fix build against latest LV2: https://github.com/antanasbruzas/abGate/pull/3

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Noise gate LV2 plugin

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		compiler:c++11-lang gl gmake gnome pkgconfig qt:5 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	antanasbruzas
USE_CXXSTD=	c++11
USE_QT=		core gui widgets buildtools_build qmake_build
USE_GL=		gl
USE_GNOME=	atkmm gtk20 gtkmm24 libsigc++20
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e ' \
		s|PREFIX = |PREFIX ?= |; \
		s|g++|$$(CXX)|; \
		s|CPPFLAGS|CXXFLAGS|; \
		s| -g -O3||; \
		s|cd abGateQt; qmake; make|cd abGateQt; $(QMAKE) \&\& $$(MAKE)|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E ' \
		s|^QMAKE_CXXFLAGS (.*)|QMAKE_CXXFLAGS = ${CXXFLAGS}|; \
		s|^QMAKE_LFLAGS (.*)|QMAKE_LFLAGS = ${LDFLAGS}|' \
		${WRKSRC}/abGateQt/abGateQt.pro

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/abGate.lv2/*.so

.include <bsd.port.mk>
