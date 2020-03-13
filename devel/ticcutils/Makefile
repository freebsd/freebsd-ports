# $FreeBSD$

PORTNAME=	ticcutils
DISTVERSIONPREFIX=	v
DISTVERSION=	0.20
PORTREVISION=	10
CATEGORIES=	devel textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic utility library shared by the Tilburg University software

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive
LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libicui18n.so:devel/icu \
		libtar.so:devel/libtar

USES=		autoreconf compiler:c++11-lib gmake gnome libtool localbase:ldflags pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_GITHUB=	yes
GH_ACCOUNT=	LanguageMachines
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CFLAGS+=	-D_THREAD_SAFE # configure on GCC-based architectures fails w/out this
# Workaround for https://github.com/LanguageMachines/ticcutils/issues/18 (also see the patch files/patch-configure.ac)
CXXFLAGS+=	-DHAVE_BOOST_REGEX
LDFLAGS+=	-lboost_regex

.include <bsd.port.mk>
