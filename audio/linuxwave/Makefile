PORTNAME=	linuxwave
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate music from the entropy of Linux
WWW=		https://orhun.dev/linuxwave/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zig>=0.14.0:lang/zig

USE_GITHUB=	yes
GH_ACCOUNT=	orhun
GH_TUPLE=	Hejsil:zig-clap:0.10.0:zig_clap/../.cache/zig/p/clap-0.10.0-oBajB434AQBDh-Ei3YtoKIRxZacVPF1iSwp3IX_ZB8f0
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

do-build:
	@(cd ${WRKSRC} && ${MAKE_ENV} zig build ${CONFIGURE_ARGS})

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

do-test:
	@(cd ${WRKSRC} && ${TEST_ENV} zig build test ${CONFIGURE_ARGS})

.include <bsd.port.mk>
