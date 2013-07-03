# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freecell-solver
PORTVERSION=	3.20.1
CATEGORIES=	games
MASTER_SITES=	http://fc-solve.shlomifish.org/downloads/fc-solve/

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Open source framework for solving Freecell

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.txt

OPTIONS_DEFINE=	TCMALLOC DOCS EXAMPLES
TCMALLOC_DESC=	Use Google's TCMalloc

USE_BZIP2=	yes
USES=		cmake:outsource
USE_PERL5_BUILD=	yes
CMAKE_ARGS=	-DFCS_WITH_TEST_SUITE:BOOL=OFF
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include

MAN6=		fc-solve-board_gen.6 fc-solve.6 \
		freecell-solver-range-parallel-solve.6 \
		make-aisleriot-freecell-board.6 make-gnome-freecell-board.6 \
		make_pysol_freecell_board.py.6 \
		pi-make-microsoft-freecell-board.6

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTCMALLOC}
LIB_DEPENDS+=	tcmalloc:${PORTSDIR}/devel/google-perftools
.else
CMAKE_ARGS+=	-DFCS_AVOID_TCMALLOC:BOOL=ON
.endif

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
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in AUTHORS.txt HACKING.txt INSTALL.txt NEWS.txt README.txt \
	README.win32.txt TODO.txt USAGE.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
.for f in ctypes-test.py
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
