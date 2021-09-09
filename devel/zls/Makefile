PORTNAME=	zls
DISTVERSION=	0.1.0-226
DISTVERSIONSUFFIX=	-g39d8718
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Zig LSP implementation + Zig Language Server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	zig>=0.8.0:lang/zig
RUN_DEPENDS=	zig:lang/zig

USE_GITHUB=	yes
GH_ACCOUNT=	zigtools
GH_TUPLE=	ziglibs:known-folders:0.7.0-6-ge179436:known_folders/src/known-folders \
		ziglibs:zinput:0.1.0-16-g95106b1:zinput/src/zinput
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
