# ex:ts=8
# New ports collection makefile for:   freecell-solver
# Date created:                Fab 9, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freecell-solver
PORTVERSION=	3.6.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		BERLIOS/fc-solve

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program that automatically solves games of Freecell

LICENSE=	MIT

OPTIONS=	TCMALLOC "Use Google's TCMalloc" off

USE_BZIP2=	yes
USE_PERL5_BUILD=	yes
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

MAN6=	fc-solve-board_gen.6 \
	fc-solve.6 \
	freecell-solver-range-parallel-solve.6 \
	make-aisleriot-freecell-board.6 \
	make-gnome-freecell-board.6 \
	make_pysol_freecell_board.py.6 \
	pi-make-microsoft-freecell-board.6

CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.pre.mk>

.if defined(WITH_TCMALLOC)
LIB_DEPENDS+=	tcmalloc.1:${PORTSDIR}/devel/google-perftools
CMAKE_ARGS+=	-DFCS_USE_TCMALLOC:BOOL=ON
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' \
		${WRKSRC}/Presets/presets/children-playing-ball.sh \
		${WRKSRC}/Presets/presets/sentient-pearls.sh

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS.txt HACKING.txt INSTALL.txt NEWS.txt README.txt \
	README.win32.txt TODO.txt USAGE.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for file in ctypes-test.py
	${INSTALL_DATA} ${WRKSRC}/examples/${file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.post.mk>
