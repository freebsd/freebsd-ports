PORTNAME=	zls
DISTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Zig LSP implementation + Zig Language Server
WWW=		https://github.com/zigtools/zls

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zig>=0.10.0:lang/zig
RUN_DEPENDS=	zig:lang/zig

USE_GITHUB=	yes
GH_ACCOUNT=	zigtools
GH_TUPLE=	ziglibs:known-folders:0.7.0-20-g24845b0:known_folders/src/known-folders \
		wolfpld:tracy:v0.8.2.1:tracy/src/tracy
MAKE_ENV=	DESTDIR="${STAGEDIR}"
CONFIGURE_ARGS=	--prefix "${PREFIX}" \
		${WITH_DEBUG:D:U-Drelease-fast} \
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
