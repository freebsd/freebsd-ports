PORTNAME=	linuxwave
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.5
PORTREVISION=	2
CATEGORIES=	audio

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	bbb9a15b41ed.patch:-p1 # https://github.com/orhun/linuxwave/pull/28

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Generate music from the entropy of Linux
WWW=		https://orhun.dev/linuxwave/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zig>=0.12.0:lang/zig

USE_GITHUB=	yes
GH_ACCOUNT=	orhun
GH_TUPLE=	Hejsil:zig-clap:0.8.0:zig_clap/libs/zig-clap
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
