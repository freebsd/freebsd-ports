# ex:ts=8
# Ports collection makefile for:	lbpp
# Date created:			Jun 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	lbpp
PORTVERSION=	0.0.6b
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A front end to GCC from Liberty Basic source code

USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomelibs

post-patch:
	@${GREP} -lR "malloc.h" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e "s/malloc.h/stdlib.h/g"
	@${FIND} ${WRKSRC} -name "Makefile*" | ${XARGS} \
		${REINPLACE_CMD} -e "s,^CC,#CC,g ; s,^CFLAGS =,CFLAGS+=,g ; \
				s,-Wall -g,,g"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lbpp ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/liblb/libLB.a ${PREFIX}/lib

.include <bsd.port.mk>
