PORTNAME=	zls
DISTVERSION=	0.9.0
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Zig LSP implementation + Zig Language Server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zig>=0.9.0:lang/zig
RUN_DEPENDS=	zig:lang/zig

USE_GITHUB=	yes
GH_ACCOUNT=	zigtools
GH_TUPLE=	ziglibs:known-folders:0.7.0-15-g9db1b99:known_folders/src/known-folders \
		ziglibs:zinput:0.1.0-19-g5e0d781:zinput/src/zinput
MAKE_ENV=	DESTDIR="${STAGEDIR}"
CONFIGURE_ARGS=	--prefix "${PREFIX}" \
		${WITH_DEBUG:U-Drelease-fast=true} \
		--verbose
NO_INSTALL=	yes # strip(1) breaks runtime
PLIST_FILES=	bin/${PORTNAME} \
		bin/build_runner.zig

post-patch:
# Respect PREFIX for global_configuration
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		${WRKSRC_known_folders}/known-folders.zig

do-build:
	@(cd ${WRKSRC} && ${MAKE_ENV} zig build ${CONFIGURE_ARGS})

do-test:
	@(cd ${WRKSRC} && ${TEST_ENV} zig build test ${CONFIGURE_ARGS})

.include <bsd.port.mk>
