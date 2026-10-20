PORTNAME=	libmustache
PORTVERSION=	0.6.2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ implementation of Mustache
WWW=		https://github.com/jbboehr/libmustache

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		autoreconf compiler:c++17-lang libtool localbase pkgconfig

CONFIGURE_ARGS=	--enable-thread-sanitizer \
		--with-system-cista=no \
		--without-mustache-spec
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check-am
TEST_WRKSRC=	${WRKSRC}/tests
USE_CXXSTD=	c++17

GH_ACCOUNT=	jbboehr
USE_GITHUB=	yes

OPTIONS_DEFINE=	JSON YAML
OPTIONS_DEFAULT=JSON YAML

JSON_CONFIGURE_OFF=	--with-json=no
JSON_CONFIGURE_ON=	--with-json=yes
JSON_BUILD_DEPENDS=	nlohmann-json>=3.10.5:devel/nlohmann-json
YAML_CONFIGURE_OFF=	--with-yaml=no
YAML_CONFIGURE_ON=	--with-yaml=yes
YAML_LIB_DEPENDS=	libyaml.so:textproc/libyaml

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*}
# TSan is not supported on FreeBSD/powerpc64*
CONFIGURE_ARGS+=	--disable-thread-sanitizer
.endif

.if ${ARCH} == powerpc64
# archived-template support, the only user of xxHash, requires a little-endian
# target
CONFIGURE_ARGS+=	--with-system-xxhash=no
.else
LIB_DEPENDS+=	libxxhash.so:devel/xxhash
CONFIGURE_ARGS+=	--with-system-xxhash=yes
.endif

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/vendor/xxhash/

.include <bsd.port.mk>
