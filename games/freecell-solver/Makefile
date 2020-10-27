# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freecell-solver
PORTVERSION=	6.2.0
CATEGORIES=	games
MASTER_SITES=	http://fc-solve.shlomifish.org/downloads/fc-solve/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Open source framework for solving Freecell

LICENSE=	MIT

BUILD_DEPENDS=	p5-Path-Tiny>=0.076:devel/p5-Path-Tiny \
		p5-Template-Toolkit>=2.26:www/p5-Template-Toolkit \
		p5-Moo>=2.0:devel/p5-Moo \
		gperf:devel/gperf \
		asciidoctor:textproc/rubygem-asciidoctor \
		${LOCALBASE}/include/rinutils/rinutils.h:devel/rinutils \
		${PYTHON_PKGNAMEPREFIX}random2>=1.0.1:math/py-random2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.11.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysol-cards>=0.10.0:games/py-pysol-cards@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}random2>=1.0.1:math/py-random2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.11.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysol-cards>=0.10.0:games/py-pysol-cards@${PY_FLAVOR}
LIB_DEPENDS=	${LIB_DEPENDS_${ARCH}}
LIB_DEPENDS_i386=	libgmp.so:math/gmp

OPTIONS_DEFINE=	DOCS TCMALLOC
TCMALLOC_DESC=	Use Google's TCMalloc

USES=		cmake compiler:c11 localbase perl5 python:3.4+ shebangfix tar:xz
USE_PERL5=	build
SHEBANG_FILES=	board_gen/make_pysol_freecell_board.py \
		board_gen/transpose-freecell-board.py \
		board_gen/find-freecell-deal-index.py \
		board_gen/fc_solve_find_index_s2ints.py \
		board_gen/gen-multiple-pysol-layouts \
		patsolve/patsolve/param.py
CMAKE_ARGS=	-DFCS_WITH_TEST_SUITE:BOOL=OFF
USE_LDCONFIG=	yes

TCMALLOC_LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools
TCMALLOC_CMAKE_OFF=	-DFCS_AVOID_TCMALLOC:BOOL=ON

post-patch:
.for f in Shlomif_Common.cmake
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/cmake/${f}
.endfor
.for f in children-playing-ball.sh sentient-pearls.sh
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' ${WRKSRC}/Presets/presets/${f}
.endfor
	@${REINPLACE_CMD} -e 's|"python3"|"${PYTHON_VERSION}"|' ${WRKSRC}/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS.asciidoc HACKING.asciidoc INSTALL.asciidoc NEWS.asciidoc README.asciidoc \
	README.win32.txt TODO.asciidoc USAGE.asciidoc
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
