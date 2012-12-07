# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lbpp
PORTVERSION=	0.0.6b
PORTREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Front end to GCC from Liberty Basic source code

DEPRECATED=	Dead upstream since 2001
EXPIRATION_DATE=	2013-01-12

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomelibs
MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${GREP} -lR "malloc.h" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e "s/malloc.h/stdlib.h/g"
	@${FIND} ${WRKSRC} -name "Makefile*" | ${XARGS} \
		${REINPLACE_CMD} -e "s,^CC,#CC,g ; s,^CFLAGS =,CFLAGS+=,g ; \
				s,-Wall -g,,g"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lbpp ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/liblb/libLB.a ${PREFIX}/lib

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not install on powerpc: runaway process
.endif

.include <bsd.port.post.mk>
