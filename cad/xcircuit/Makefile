# New ports collection makefile for:	xcircuit
# Date created:		3 Apr 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	xcircuit
PORTVERSION=	2.3.3
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	http://xcircuit.ece.jhu.edu/archive/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript-gnu
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
USE_XPM=	yes
USE_IMAKE=	yes
USE_REINPLACE=	yes
XMKMF=		xmkmf

MAN1=		xcircuit.1

post-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>|g'

post-install:
	@${MKDIR} ${PREFIX}/share/examples/xcircuit
	${TAR} -C ${WRKSRC}/examples --exclude CVS -cf - . | \
		${TAR} -C ${PREFIX}/share/examples/xcircuit --unlink -xf -

.include <bsd.port.mk>
