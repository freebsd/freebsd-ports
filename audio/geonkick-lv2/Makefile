# $FreeBSD$

PORTNAME=	geonkick
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.2
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software percussion synthesizer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		gmake:devel/gmake \
		rapidjson>0:devel/rapidjson \
		redkite>0:x11-toolkits/redkite
LIB_DEPENDS=	libjack.so:audio/jack \
		libsndfile.so:audio/libsndfile

USES=		compiler:c++14-lang cmake:noninja gnome localbase:ldflags \
		pkgconfig shared-mime-info xorg
USE_GITLAB=	yes
GL_ACCOUNT=	geontime
GL_COMMIT=	e45f118572980ce1bfd6c11ee0b4c2db7b06f9f0
USE_GNOME=	cairo
USE_XORG=	x11

CMAKE_ARGS=	-DFREEBSD_GMAKE=${GMAKE}

#INSTALLS_ICONS=	yes # disabled because it causes: gtk-update-icon-cache: Failed to open file /usr/local/share/icons/hicolor/.icon-theme.cache : Permission denied

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
EXTRA_PATCHES=	${FILESDIR}/extra-patch-plugin_lv2_CMakeLists.txt \
		${FILESDIR}/extra-patch-standalone_CMakeLists.txt
.endif

.include <bsd.port.post.mk>
