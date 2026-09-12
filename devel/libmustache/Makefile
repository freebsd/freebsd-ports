PORTNAME=	libmustache
PORTVERSION=	0.6.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ implementation of Mustache
WWW=		https://github.com/jbboehr/libmustache

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libxxhash.so:devel/xxhash

USES=		autoreconf compiler:c++17-lang libtool localbase pkgconfig

CONFIGURE_ARGS=	--enable-thread-sanitizer \
		--with-system-cista=no \
		--with-system-xxhash=yes \
		--without-mustache-spec
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
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

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/vendor/xxhash/

.include <bsd.port.mk>
