PORTNAME=	ticcutils
DISTVERSION=	0.36
PORTREVISION=	2
CATEGORIES=	devel textproc
MASTER_SITES=	https://github.com/LanguageMachines/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic utility library shared by the Tilburg University software
WWW=		https://github.com/LanguageMachines/ticcutils

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libicui18n.so:devel/icu

USES=		compiler:c++17-lang gmake gnome libtool localbase:ldflags \
		pathfix pkgconfig
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

USE_CXXSTD=	c++17
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-static

INSTALL_TARGET=	install-strip
TEST_TARGET=	check # 1 test fails, see https://github.com/LanguageMachines/ticcutils/issues/26
TEST_ENV=	LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|-O3||g' \
		${PATCH_WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
