# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freecell-solver
PORTVERSION=	4.6.0
CATEGORIES=	games
MASTER_SITES=	http://fc-solve.shlomifish.org/downloads/fc-solve/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Open source framework for solving Freecell

LICENSE=	MIT

BUILD_DEPENDS=	p5-Path-Tiny>=0.076:devel/p5-Path-Tiny \
		p5-Template-Toolkit>=2.26:www/p5-Template-Toolkit \
		gperf:devel/gperf

OPTIONS_DEFINE=	TCMALLOC DOCS EXAMPLES
TCMALLOC_DESC=	Use Google's TCMalloc

USES=		cmake:outsource compiler:c11 perl5 shebangfix tar:xz
USE_PERL5=	build
SHEBANG_FILES=	board_gen/make_pysol_freecell_board.py
CMAKE_ARGS=	-DFCS_WITH_TEST_SUITE:BOOL=OFF
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include

TCMALLOC_LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools
TCMALLOC_CMAKE_OFF=	-DFCS_AVOID_TCMALLOC:BOOL=ON

post-patch:
.for f in CMakeLists.txt
	@${REINPLACE_CMD} -e 's|"pthread"|"-pthread"|' ${WRKSRC}/${f}
.endfor
.for f in Shlomif_Common.cmake
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/cmake/${f}
.endfor
.for f in children-playing-ball.sh sentient-pearls.sh
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' ${WRKSRC}/Presets/presets/${f}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS.txt HACKING.txt INSTALL.txt NEWS.txt README.txt \
	README.win32.txt TODO.txt USAGE.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ctypes-test.py
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
