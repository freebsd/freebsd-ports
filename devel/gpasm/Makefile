# New ports collection makefile for:	gpasm
# Date created:				4 Aug 2000
# Whom:					Samuel Tardieu <sam@inf.enst.fr>
#
# $FreeBSD$
#

PORTNAME=	gpasm
PORTVERSION=	0.8.9
CATEGORIES=	devel
MASTER_SITES=	http://download.sourceforge.net/gpasm/

MAINTAINER=	sam@inf.enst.fr

WRKSRC=		${WRKDIR}/${PORTNAME}-0.0.8
GNU_CONFIGURE=	yes
MAKE_ARGS=	DATADIR=${PREFIX}/share/gpasm

post-install:
	strip ${PREFIX}/bin/gpasm

.include <bsd.port.mk>
