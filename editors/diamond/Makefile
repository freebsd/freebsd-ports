PORTNAME=	diamond
DISTVERSION=	1.3.7
CATEGORIES=	editors
MASTER_SITES=	https://download.copperspice.com/${PORTNAME}/source/
PKGNAMESUFFIX=	-cs
DISTNAME=	Diamond-${DISTVERSION}

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Compact programmers editor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386

LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell
BUILD_DEPENDS=	copperspice>=1.7:x11-toolkits/copperspice
RUN_DEPENDS=	copperspice>=1.7:x11-toolkits/copperspice

USES=		compiler:c++17-lang cmake dos2unix gl gnome iconv jpeg pkgconfig ssl tar:bz2 xorg
USE_GL=		gl
USE_GNOME=	cairo glib20 libxml2
USE_XORG=	ice sm x11 xau xcb xcursor xext xfixes xi xinerama xrandr xrender

# It's a bit up-in-the-air if the GitHub tarballs are less fragile
# than the upstream source tarballs, which have their own peculiarities
# (e.g. CRLF, no subdir). We dos2unix the files that need patching.
#
# USE_GITHUB=	yes
# GH_ACCOUNT=	copperspice
# GH_PROJECT=	diamond
#
NO_WRKSUBDIR=	yes
DOS2UNIX_FILES=	CMakeLists.txt src/CMakeLists.txt src/json.cpp src/recent_tabs.cpp

.include <bsd.port.mk>
