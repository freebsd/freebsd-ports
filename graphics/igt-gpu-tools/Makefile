PORTNAME=	igt-gpu-tools
DISTVERSION=	1.26.1266
CATEGORIES=	graphics

MAINTAINER=	jfree@FreeBSD.org
COMMENT=	IGT gpu tools and tests
WWW=		https://drm.pages.freedesktop.org/igt-gpu-tools/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rst2man:textproc/py-docutils@${PY_FLAVOR}
LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libdw.so:devel/elfutils \
		libpciaccess.so:devel/libpciaccess \
		libudev.so:devel/libudev-devd

USES=		bison gnome meson pkgconfig python shebangfix xorg

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	drm
GL_TAGNAME=	9338ab3ec085292817ab1e74d1f2fb90b6a98332

USE_GNOME=	cairo glib20

USE_LDCONFIG=	yes

USE_XORG=	pixman

SHEBANG_FILES=	scripts/code_cov_gather_on_test scripts/code_cov_parse_info
MESON_ARGS=	-Dvalgrind=disabled

OPTIONS_DEFINE=		CHAMELIUM DOCS RUNNER TEST
OPTIONS_DEFAULT=	DOCS RUNNER TEST

OPTIONS_SUB=	yes

CHAMELIUM_DESC=	Build chamelium display tests
RUNNER_DESC=	Build test runner

CHAMELIUM_IMPLIES=		TEST
CHAMELIUM_LIB_DEPENDS=		libasound.so:audio/alsa-lib \
				libcurl.so:ftp/curl \
				libgsl.so:math/gsl \
				libxmlrpc.so:net/xmlrpc-c
CHAMELIUM_MESON_ENABLED=	chamelium

DOCS_IMPLIES=		TEST
DOCS_BUILD_DEPENDS=	gtkdoc-mkhtml:textproc/gtk-doc
DOCS_MESON_ENABLED=	docs

RUNNER_IMPLIES=		TEST
RUNNER_LIB_DEPENDS=	libjson-c.so:devel/json-c \
			liboping.so:net/liboping
RUNNER_MESON_ENABLED=	runner

TEST_LIB_DEPENDS=	libunwind.so:devel/libunwind
TEST_MESON_ENABLED=	tests

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
PLIST_SUB+=	AMD64=""
.else
PLIST_SUB+=	AMD64="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
