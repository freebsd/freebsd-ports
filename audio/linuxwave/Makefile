PORTNAME=	linuxwave
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.5
CATEGORIES=	audio

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Generate music from the entropy of Linux
WWW=		https://orhun.dev/linuxwave/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zig010>=0.10.0:lang/zig010

USE_GITHUB=	yes
GH_ACCOUNT=	orhun
GH_TUPLE=	Hejsil:zig-clap:0.6.0:zig_clap/libs/zig-clap
MAKE_ENV=	DESTDIR="${STAGEDIR}"
CONFIGURE_ARGS=	--prefix "${PREFIX}" \
		${WITH_DEBUG:D:U-Drelease-fast} \
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
