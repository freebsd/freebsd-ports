PORTNAME=	libgpr
DISTVERSIONPREFIX=	v
DISTVERSION=	24.0.0
CATEGORIES=	devel

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Library from GPRbuild
WWW=		https://www.adacore.com/gems/gem-65

LICENSE=	GPLv3+ GPLv3RLE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING3

BUILD_DEPENDS=	gprbuild>=23:devel/gprbuild
LIB_DEPENDS=	libxmlada_dom.so:textproc/xmlada

USES=		ada:12,run gmake
USE_BINUTILS=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	AdaCore
GH_PROJECT=	gprbuild

MAKE_ENV=	GPR_PROJECT_PATH=${PREFIX}/share/gpr
ALL_TARGET=	libgpr.build
INSTALL_TARGET=	libgpr.install

GCC_VER=	12
PLIST_SUB=	GCC_VER=${GCC_VER}

pre-configure:
	${REINPLACE_CMD} -e '/^LIB_INSTALLER/s|prefix=|prefix=${STAGEDIR}|'	\
		${WRKSRC}/${MAKEFILE}

post-install:
	${STRIP_CMD}	\
		${STAGEDIR}${PREFIX}/gnat${GCC_VER}/lib/gpr/relocatable/gpr/libgpr.so

.include <bsd.port.mk>
