# New ports collection makefile for:	cfdg
# Date created:		2008-03-14
# Whom:			Anatoly Borodin <anatoly.borodin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	cfdg
PORTVERSION=	2.2.1
CATEGORIES=	graphics math
MASTER_SITES=	http://www.contextfreeart.org/download/ \
		http://glyphic.s3.amazonaws.com/cfa/download/
DISTNAME=	ContextFreeSource${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	anatoly.borodin@gmail.com
COMMENT=	Context Free Design Grammar compiler

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_BISON=	build
USE_GMAKE=	yes

NO_INSTALL_MANPAGES=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cfdg ${PREFIX}/bin
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/input/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
