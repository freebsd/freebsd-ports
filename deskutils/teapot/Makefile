# New ports collection makefile for:	teapot
# Version required:			1.01
# Date created:				7 January 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1998/03/27 10:31:46 tg Exp $
#

DISTNAME=	teapot-1.01
CATEGORIES=	deskutils
MASTER_SITES=	ftp://cantor.informatik.rwth-aachen.de/pub/unix/

MAINTAINER=	andy@icc.surw.chel.su

ALL_TARGET=
MAN1=		teapot.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/teapot ${PREFIX}/bin
	@ cd ${WRKSRC}/doc; make teapot.doc teapot.html teapot.ps
	@ ${INSTALL_MAN} ${WRKSRC}/teapot.1.en ${PREFIX}/man/man1/teapot.1
	@ ${MKDIR} ${PREFIX}/share/examples/teapot
.for file in asqrt asqrt.README counter counter.README life life.README sqrt sqrt.README
	@ ${INSTALL_DATA} ${WRKSRC}/examples/${file} ${PREFIX}/share/examples/teapot
.endfor
	@ ${MKDIR} ${PREFIX}/share/doc/teapot
	@ ${INSTALL_DATA} ${WRKSRC}/README-en.html ${PREFIX}/share/doc/teapot/README.html
.for file in teapot.doc teapot.html teapot.ps
	@ ${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/share/doc/teapot
.endfor

.include <bsd.port.mk>
