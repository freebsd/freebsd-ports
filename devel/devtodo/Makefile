# New ports collection makefile for:	devtodo
# Date Created:				26 May 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	devtodo
PORTVERSION=	0.1.18
CATEGORIES=	devel
MASTER_SITES=	http://swapoff.org/files/devtodo/

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Tool to effectively maintain todo lists aimed at developers

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

# Note: without this define util/regex.c doesn't compile due to redeclaration
# of malloc and realloc functions. Adding this define was the simplest
# (although not elegant) solution.
CFLAGS+=	-DSTDC_HEADERS

MAN1=	devtodo.1
MLINKS=	devtodo.1 tda.1 devtodo.1 tdd.1 devtodo.1 tde.1 devtodo.1 tdl.1 \
	devtodo.1 tdr.1 devtodo.1 todo.1
MANCOMPRESSED=	no

post-patch:
	@${REINPLACE_CMD} -e 's/^\ttest -f.*todorc.*\n//' ${WRKSRC}/doc/Makefile.in

post-install:
	@${MKDIR} ${EXAMPLESDIR}
.for file in scripts.sh scripts.tcsh todorc.example
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${EXAMPLESDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/todorc.example ${PREFIX}/etc/todorc.sample

.include <bsd.port.mk>
