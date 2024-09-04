PORTNAME=	zls
DISTVERSION=	0.14.0
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Zig LSP implementation + Zig Language Server
WWW=		https://github.com/zigtools/zls

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zig>=0.14.0:lang/zig
RUN_DEPENDS=	zig:lang/zig

USE_GITHUB=	yes
GH_ACCOUNT=	zigtools
GH_TUPLE=	wolfpld:tracy:v0.11.1:tracy/../.cache/zig/p/N-V-__8AAMeOlQEipHjcyu0TCftdAi9AQe7EXUDJOoVe0k-t \
		ziglibs:diffz:ef45c00:diffz/../.cache/zig/p/N-V-__8AABhrAQAQLLLGadghhPsdxTgBk9N9aLVOjXW3ay0V \
		ziglibs:known-folders:0.7.0-57-gaa24df4:known_folders/../.cache/zig/p/known_folders-0.0.0-Fy-PJtLDAADGDOwYwMkVydMSTp_aN-nfjCZw6qPQ2ECL \
		zigtools:zig-lsp-codegen:063a98c:zig_lsp_codegen/../.cache/zig/p/lsp_codegen-0.1.0-CMjjo0ZXCQB-rAhPYrlfzzpU0u0u2MeGvUucZ-_g32eg
MAKE_ENV=	DESTDIR="${STAGEDIR}"
CONFIGURE_ARGS=	--prefix "${PREFIX}" \
		${WITH_DEBUG:D:U-Doptimize=ReleaseFast} \
		-Dcpu=${CPUTYPE:Ubaseline} \
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
