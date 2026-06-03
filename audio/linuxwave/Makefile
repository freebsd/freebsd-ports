PORTNAME=	linuxwave
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate music from the entropy of Linux
WWW=		https://orhun.dev/linuxwave/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		zig

USE_GITHUB=	yes
GH_ACCOUNT=	orhun

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

do-test:
	@(cd ${WRKSRC} && ${TEST_ENV} zig build test ${CONFIGURE_ARGS})

.include <bsd.port.mk>
