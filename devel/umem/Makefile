# New ports collection makefile for:	umem
# Date created:				02 October 2006
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	umem
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	https://labs.omniti.com/portableumem/releases/${PORTVERSION}/

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A port of the Solaris memory allocator

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15

post-patch:
	@${REINPLACE_CMD} -e 's/ -ldl//g' ${WRKSRC}/Makefile.in

MAN3=		umem_alloc.3 umem_cache_create.3 umem_debug.3

.include <bsd.port.pre.mk>

# pthread
.if ${OSVERSION} < 502102
IGNORE=		requires FreeBSD 5.2.1 or above
.endif

.include <bsd.port.post.mk>
