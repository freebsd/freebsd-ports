# Created by: Andrew Elble <aweits@rit.edu>
# $FreeBSD$

PORTNAME=	ding-libs
PORTVERSION=	0.6.1
CATEGORIES=	devel
MASTER_SITES=	https://releases.pagure.org/SSSD/ding-libs/ \
		LOCAL/tobik/ding-libs
DIST_SUBDIR=	ding-libs

# Build fixes for non-Linux systems
PATCH_SITES=	LOCAL/tobik/ding-libs \
		https://pagure.io/SSSD/ding-libs/c/
PATCHFILES=	8fc522605a90e670fe76dc1b44669230c121a96e.patch:-p1 \
		72c19bd018b107ecf5a80963b433e9922f7243fd.patch:-p1 \
		315a0d527e0734ed2fd4529c9b685e41d2ce5dad.patch:-p1 \
		be9ca3a2c26b061d1f22bd4a09009bba7a01f67b.patch:-p1 \
		a731d8c8c515e7e42a4fb448e0ecb6934d5bf99b.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of useful libraries for developers

LICENSE=	GPLv3+ LGPL3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3+ =	${WRKSRC}/COPYING.LESSER

USES=		iconv gettext-runtime libtool localbase
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
CONFIGURE_ENV=	DOXYGEN=""
LIBS+=		${ICONV_LIB} -lintl
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS TEST

# libcheck is required to run *all* the unit tests.
# Without it only 14/20 tests will run.
TEST_BUILD_DEPENDS=	check>=0:devel/check
TEST_USES=		pkgconfig

.include <bsd.port.mk>
