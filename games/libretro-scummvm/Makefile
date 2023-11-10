PORTNAME=	libretro-scummvm
DISTVERSION=	0.20231021
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ScummVM with libretro backend
WWW=		https://github.com/libretro/scummvm

LICENSE=	GPLv2

BROKEN=		requires network access

BUILD_DEPENDS=	bash:shells/bash \
		git:devel/git

USES=		compiler:c++11-lib gmake shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yesx
GH_ACCOUNT=	libretro
GH_PROJECT=	scummvm
GH_TAGNAME=	d836ec97edb3aca21ab1d2aea6a4dbf00420cbf9

PLIST_FILES=	lib/libretro/scummvm_libretro.so

BUILD_WRKSRC=	${WRKSRC}/backends/platform/libretro

SHEBANG_FILES=	backends/platform/libretro/scripts/*.sh

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${BUILD_WRKSRC}/scummvm_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
