# New ports collection makefile for:	boehm-gc
# Date created:		15 November 1996
# Whom:			Mike McGaughey <mmcg@cs.monash.edu.au>
#
# $FreeBSD$
#

PORTNAME=	boehm-gc
PORTVERSION=	6.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.hpl.hp.com/personal/Hans_Boehm/gc/gc_source/
DISTNAME=	gc${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org

USE_LIBTOOL=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --disable-threads

MAN3=		gc.3

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/doc/gc.man

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/gc.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/gc_backptr.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/gc_cpp.h ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/doc/gc.man ${PREFIX}/man/man3/gc.3

.include <bsd.port.mk>
