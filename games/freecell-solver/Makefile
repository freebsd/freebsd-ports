# ex:ts=8
# New ports collection makefile for:   freecell-solver
# Date created:                Fab 9, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freecell-solver
PORTVERSION=	3.8.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	BERLIOS/fc-solve

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program that automatically solves games of Freecell

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USE_BZIP2=		yes
USE_PERL5_BUILD=	yes
USE_CMAKE=		yes
USE_LDCONFIG=		yes
MAKE_JOBS_SAFE=		yes

MAN6=		fc-solve-board_gen.6 fc-solve.6 \
		freecell-solver-range-parallel-solve.6 \
		make-aisleriot-freecell-board.6 make-gnome-freecell-board.6 \
		make_pysol_freecell_board.py.6 \
		pi-make-microsoft-freecell-board.6

CFLAGS+=	-I${LOCALBASE}/include

OPTIONS=	TCMALLOC "Use Google's TCMalloc" off

.include <bsd.port.pre.mk>

.if defined(WITH_TCMALLOC)
LIB_DEPENDS+=	tcmalloc.2:${PORTSDIR}/devel/google-perftools
.else
CMAKE_ARGS+=	-DFCS_AVOID_TCMALLOC:BOOL=ON
.endif

post-patch:
.for f in children-playing-ball.sh sentient-pearls.sh
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' ${WRKSRC}/Presets/presets/${f}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in AUTHORS.txt HACKING.txt INSTALL.txt NEWS.txt README.txt \
	README.win32.txt TODO.txt USAGE.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for f in ctypes-test.py
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.post.mk>
