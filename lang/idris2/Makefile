PORTNAME=	idris2
DISTVERSION=	0.8.0
CATEGORIES=	lang
MASTER_SITES=	https://www.idris-lang.org/releases/

MAINTAINER=	freebsd-ports@jan0sch.de
COMMENT=	Programming language for Type-Driven Development
WWW=		https://www.idris-lang.org/ \
		https://github.com/idris-lang/Idris2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	chez-scheme:lang/chez-scheme
LIB_DEPENDS=	libgmp.so:math/gmp
RUN_DEPENDS=	chez-scheme:lang/chez-scheme

USES=	gmake tar:tgz

WRKSRC=	${WRKDIR}/Idris2-${DISTVERSION}

do-build:
	@cd ${WRKSRC} && ${MAKE_CMD} bootstrap SCHEME=chez-scheme HOMEBREW_PREFIX=${PREFIX} PREFIX=${PREFIX}

post-build:
	@cd ${WRKSRC} && ${SED} -i'' -e "s#(define IdrisPaths-yprefix \".*\")#(define IdrisPaths-yprefix \"${PREFIX}\")#" \
		build/exec/idris2_app/idris2.ss

do-install:
	@cd ${WRKSRC} && ${MAKE_CMD} install IDRIS2_PREFIX=${PREFIX} PREFIX=${PREFIX} DESTDIR=${STAGEDIR}

post-install:
	@${SED} -i '' -e '1s|^#!/usr/bin/chez|#!${LOCALBASE}/bin/chez-scheme|' \
		${STAGEDIR}${PREFIX}/bin/idris2_app/idris2-boot.ss \
		${STAGEDIR}${PREFIX}/bin/idris2_app/idris2-boot.so
	@${RM} -r ${STAGEDIR}${PREFIX}/idris2-${DISTVERSION}/test-${DISTVERSION}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/idris2_app/libidris2_support.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/idris2-${DISTVERSION}/lib/libidris2_support.so

do-test:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} test SCHEME=chez-scheme INTERACTIVE=''

.include <bsd.port.mk>
