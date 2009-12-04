# New ports collection makefile for:	stalin
# Date created:				10/23/2009
# Whom:					stas
#
# $FreeBSD$
#

PORTNAME=	stalin
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/
DISTNAME=	stalin-freebsd-${PORTVERSION}_1

MAINTAINER=	stas@FreeBSD.org
COMMENT=	An aggressive optimizing Scheme compiler

LIB_DEPENDS=	gc.1:${PORTSDIR}/devel/boehm-gc

USE_BZIP2=	yes
ONLY_FOR_ARCHS=	i386 amd64 sparc64
ONLY_FOR_ARCHS_REASON=	has not been bootstrapped on other platforms yet

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
STALIN_SRC=	"stalin-IA32.c"
.elif ${ARCH} == "amd64"
STALIN_SRC=	"stalin-AMD64.c"
.elif ${ARCH} == "sparc64"
STALIN_SRC=	"stalin-SPARC64.c"
.endif
STALIN_LIBDIR=	${PREFIX}/lib/stalin

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64: includes i386 asm
.endif

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
SUB_FILES=	stalin.sh
MAN1=	stalin.1

do-build:
	(cd ${WRKSRC}/ && ${CC} -o stalin -I${LOCALBASE}/include \
	    -L${LOCALBASE}/lib -lgc -lm ${CFLAGS} ${STALIN_SRC})
	ar -rc ${WRKSRC}/libstalin.a

do-install:
	${MKDIR} ${STALIN_LIBDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/stalin ${STALIN_LIBDIR}/
	(cd ${WRKSRC}/include && ${COPYTREE_SHARE} \* ${STALIN_LIBDIR}/)
	${CHMOD} 755 ${STALIN_LIBDIR}
	${CHMOD} a+x ${STALIN_LIBDIR}/stalin-architecture-name
	${INSTALL_SCRIPT} ${WRKDIR}/stalin.sh ${PREFIX}/bin/stalin
	${INSTALL_MAN} ${WRKSRC}/stalin.1 ${MAN1PREFIX}/man/man1/
	${INSTALL_DATA} ${WRKSRC}/stalin.el ${EMACSLISPDIR}/
	${INSTALL_DATA} ${WRKSRC}/libstalin.a ${STALIN_LIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
