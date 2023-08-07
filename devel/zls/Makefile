PORTNAME=	zls
DISTVERSION=	0.11.0
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Zig LSP implementation + Zig Language Server
WWW=		https://github.com/zigtools/zls

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zig>=0.11.0:lang/zig
RUN_DEPENDS=	zig:lang/zig

USE_GITHUB=	yes
GH_ACCOUNT=	zigtools
GH_TUPLE=	antlilja:8372900fcc09e38d7b0b6bbaddad3904:6c3321e:binned_allocator/../.cache/zig/p/1220363c7e27b2d3f39de6ff6e90f9537a0634199860fea237a55ddb1e1717f5d6a5 \
		wolfpld:tracy:v0.9.1:tracy/src/tracy \
		ziglibs:diffz:90353d4:diffz/../.cache/zig/p/122089a8247a693cad53beb161bde6c30f71376cd4298798d45b32740c3581405864 \
		ziglibs:known-folders:0.7.0-26-gfa75e1b:known_folders/../.cache/zig/p/122048992ca58a78318b6eba4f65c692564be5af3b30fbef50cd4abeda981b2e7fa5
MAKE_ENV=	DESTDIR="${STAGEDIR}"
CONFIGURE_ARGS=	--prefix "${PREFIX}" \
		${WITH_DEBUG:D:U-Doptimize=ReleaseFast} \
		-Dcpu=${CPUTYPE:Ubaseline} \
		-Ddata_version=${DISTVERSION} \
		--verbose
NO_INSTALL=	yes # strip(1) breaks runtime
PLIST_FILES=	bin/${PORTNAME}

post-patch:
# Respect PREFIX for global_configuration
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		${WRKSRC_known_folders}/known-folders.zig

do-build:
	@(cd ${WRKSRC} && ${MAKE_ENV} zig build ${CONFIGURE_ARGS})

do-test:
	@(cd ${WRKSRC} && ${TEST_ENV} zig build test ${CONFIGURE_ARGS})

.include <bsd.port.mk>
