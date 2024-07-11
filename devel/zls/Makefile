PORTNAME=	zls
DISTVERSION=	0.12.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://raw.githubusercontent.com/ziglang/:langref
DISTFILES=	zig/${DISTVERSION}/doc/langref.html.in:langref
EXTRACT_ONLY=	${DISTFILES:N*\:langref:C/\:.*//}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Zig LSP implementation + Zig Language Server
WWW=		https://github.com/zigtools/zls

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zig>=0.12.0:lang/zig
RUN_DEPENDS=	zig:lang/zig

USE_GITHUB=	yes
GH_ACCOUNT=	zigtools
GH_TUPLE=	wolfpld:tracy:v0.10:tracy/src/tracy \
		ziglibs:diffz:e10bf15:diffz/../.cache/zig/p/12200d71e4b7029ea56a429e24260c6c0e85a3069b0d4ba85eace21a0fd75910aa64 \
		ziglibs:known-folders:0.7.0-34-gbf79988:known_folders/../.cache/zig/p/12201314cffeb40c5e4e3da166217d2c74628c74486414aaf97422bcd2279915b9fd
MAKE_ENV=	DESTDIR="${STAGEDIR}"
CONFIGURE_ARGS=	--prefix "${PREFIX}" \
		${WITH_DEBUG:D:U-Doptimize=ReleaseFast} \
		-Dcpu=${CPUTYPE:Ubaseline} \
		-Ddata_version=${DISTVERSION} \
		-Dversion_data_path=${DISTFILES:M*\:langref:C/\:.*//:S,^,${_DISTDIR},} \
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
