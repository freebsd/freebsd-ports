# ex:ts=8
# New ports collection makefile for:   freecell-solver
# Date created:                Fab 9, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freecell-solver
PORTVERSION=	2.8.10
CATEGORIES=	games
MASTER_SITES=	http://vipe.technion.ac.il/~shlomif/freecell-solver/ \
		http://fc-solve.berlios.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program that automatically solves games of Freecell

USE_REINPLACE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

MAN6=	fc-solve-board_gen.6 fc-solve.6 \
	freecell-solver-range-parallel-solve.6 \
	make-aisleriot-freecell-board.6 \
	make-gnome-freecell-board.6 \
	make_pysol_freecell_board.py.6 \
	pi-make-microsoft-freecell-board.6

post-patch:
	@${REINPLACE_CMD} -e '/<malloc\.h>/d' ${WRKSRC}/alloc.c

.include <bsd.port.mk>
