PORTNAME=	opentimer
PORTVERSION=	g20210726
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance timing analysis tool for VLSI systems

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	undefined reference to `__atomic_compare_exchange_8'

USES=		cmake compiler:c++17-lang python:test shebangfix tcl
USE_GCC=	yes # fails to build with clang-11: https://github.com/OpenTimer/OpenTimer/issues/48

SHEBANG_FILES=	inttest/*.py

USE_GITHUB=	yes
GH_ACCOUNT=	OpenTimer
GH_PROJECT=	OpenTimer
GH_TAGNAME=	18d28ff

TEST_TARGET=	test

PLIST_FILES=	bin/ot-shell \
		bin/ot-tau15 \
		bin/ot-tau18 \
		bin/ot-utility

do-install: # see https://github.com/OpenTimer/OpenTimer/issues/47
.for e in ot-shell ot-tau15 ot-tau18 ot-utility
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${e} ${STAGEDIR}${PREFIX}/bin
.endfor

quick-test: # runs the script suggested in https://github.com/OpenTimer/OpenTimer
	@cd ${WRKSRC} && \
		bin/ot-shell < ${FILESDIR}/test.txt

.include <bsd.port.mk>
