PORTNAME=	linuxwave
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	audio

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Generate music from the entropy of Linux
WWW=		https://orhun.dev/linuxwave/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zig>=0.12.0:lang/zig

USE_GITHUB=	yes
GH_ACCOUNT=	orhun
GH_TUPLE=	Hejsil:zig-clap:0.9.1:zig_clap/../.cache/zig/p/122062d301a203d003547b414237229b09a7980095061697349f8bef41be9c30266b
MAKE_ENV=	DESTDIR="${STAGEDIR}"
CONFIGURE_ARGS=	--prefix "${PREFIX}" \
		${WITH_DEBUG:D:U-Doptimize=ReleaseFast} \
		${WITH_PIE:D-Dpie} \
		${WITH_RELRO:D-Drelro} \
		-Dcpu=${CPUTYPE:Ubaseline} \
		--verbose
NO_INSTALL=	yes # strip(1) breaks runtime
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

pre-patch:
.if defined(PATCHFILES) && ${PATCHFILES:Mbbb9a15b41ed*}
# Pretend to be a regular file for vendor patch to apply as is
	@${MV} ${WRKSRC}/libs/zig-clap ${WRKSRC}/libs/zig-clap.moved
	@${ECHO_CMD} "Subproject commit 749c43f1f846adc950a5920ed61b40cbc3ec2c54" \
		>${WRKSRC}/libs/zig-clap
.endif

post-patch:
.if defined(PATCHFILES) && ${PATCHFILES:Mbbb9a15b41ed*}
	@${RM} ${WRKSRC}/libs/zig-clap
	@${MV} ${WRKSRC}/libs/zig-clap.moved ${WRKSRC}/libs/zig-clap
.endif

do-build:
	@(cd ${WRKSRC} && ${MAKE_ENV} zig build ${CONFIGURE_ARGS})

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

do-test:
	@(cd ${WRKSRC} && ${TEST_ENV} zig build test ${CONFIGURE_ARGS})

.include <bsd.port.mk>
