# New ports collection makefile for:	xcircuit
# Date created:		3 Apr 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	xcircuit
PORTVERSION=	2.1b6
CATEGORIES=	cad
MASTER_SITES=	http://bach.ece.jhu.edu/~tim/programs/xcircuit/archive/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript55

USE_BZIP2=	yes
USE_IMAKE=	yes
USE_XPM=	yes
XMKMF=		xmkmf

MAN1=		xcircuit.1

post-install:
	@${MKDIR} ${PREFIX}/share/examples/xcircuit
	${TAR} -C ${WRKSRC}/examples --exclude CVS -cf - . | \
		${TAR} -C ${PREFIX}/share/examples/xcircuit --unlink -xf -

.include <bsd.port.mk>
