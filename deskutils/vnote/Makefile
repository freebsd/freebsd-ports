PORTNAME=	vnote
DISTVERSIONPREFIX=	v
DISTVERSION=	3.20.0
CATEGORIES=	deskutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Pleasant Qt-based note-taking platform
WWW=		https://app.vnote.fun/en_us/

LICENSE=	LGPL3

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers \
		pkgconf>0:devel/pkgconf
LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell

USES=		compiler:c++17-lang cmake desktop-file-utils gl qt:6 xorg
USE_GL=		opengl
USE_QT=		5compat base declarative imageformats pdf positioning \
		sqldriver-sqlite:run svg webchannel webengine
USE_XORG=	ice sm x11 xcb xext
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}x
GH_PROJECT=	QHotkey:qhk vtextedit:vte syntax-highlighting:shl sonnet:s
GH_TAGNAME=	d7b5250:qhk c8fe95e:vte 25f6871:shl 7320206:s
GH_SUBDIR=	libs/QHotkey:qhk libs/vtextedit:vte \
		libs/vtextedit/libs/sonnet:s \
		libs/vtextedit/libs/syntax-highlighting:shl

CMAKE_ARGS=	-DCMAKE_INSTALL_DATADIR=${DATADIR}

post-patch:
	@${REINPLACE_CMD} -E '/add_subdirectory\((demo|tests)\)/d' \
		${WRKSRC}/libs/vtextedit/CMakeLists.txt \
		${WRKSRC}/CMakeLists.txt
	@${GREP} -Rl --null Q_OS_LINUX ${WRKSRC}/src | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's,Q_OS_LINUX,Q_OS_UNIX,'
	@${REINPLACE_CMD} -e 's,%%DATADIR%%,${DATADIR},' \
		${WRKSRC}/src/core/configmgr.cpp

.include <bsd.port.mk>
