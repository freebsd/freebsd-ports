# ex:ts=8
# New ports collection makefile for:	ray++
# Date created:			Dec 6, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ray++
PORTVERSION=	0.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.mpa-garching.mpg.de/~martin/ray++/download/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A collection of C++ classes needed for ray tracing

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --enable-fast-handles
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

do-install:
	@(cd ${WRKSRC} ; \
	  ${INSTALL_DATA} ray++.so ${PREFIX}/lib ; \
	  ${FIND} * -name "*.h" | cpio -pdum ${PREFIX}/include/${PORTNAME} ; \
	  ${CHMOD} -R 755 ${PREFIX}/include/${PORTNAME} )

.include <bsd.port.mk>
