PORTNAME=	libretro-fbalpha2012
DISTVERSION=	0.20231101
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Final Burn Alpha port for libretro
WWW=		https://github.com/libretro/fbalpha2012

# Commercial users must seek permission from copyright holders.
LICENSE=	FBA
LICENSE_NAME=	FBA
LICENSE_FILE=	${WRKSRC}/src/license.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libretro/fbalpha2012_libretro.so

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	fbalpha2012
GH_TAGNAME=	b7ac554c53561d41640372f23dab15cd6fc4f0c4

CXXFLAGS+=	-Wno-c++11-narrowing

WRKSRC_SUBDIR=	svn-current/trunk
MAKEFILE=	makefile.libretro
MAKE_ARGS=	profile=performance

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/fbalpha2012_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
