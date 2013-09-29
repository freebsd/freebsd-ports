# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freecell-solver
PORTVERSION=	3.20.1
CATEGORIES=	games
MASTER_SITES=	http://fc-solve.shlomifish.org/downloads/fc-solve/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Open source framework for solving Freecell

LICENSE=	MIT

OPTIONS_DEFINE=	TCMALLOC DOCS EXAMPLES
TCMALLOC_DESC=	Use Google's TCMalloc

USE_BZIP2=	yes
USES=		cmake:outsource perl5
USE_PERL5=	build
CMAKE_ARGS=	-DFCS_WITH_TEST_SUITE:BOOL=OFF
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTCMALLOC}
LIB_DEPENDS+=	libtcmalloc.so:${PORTSDIR}/devel/google-perftools
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
