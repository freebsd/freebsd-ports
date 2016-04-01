# Created by: stas
# $FreeBSD$

PORTNAME=	stalin
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/
DISTNAME=	stalin-freebsd-${PORTVERSION}_1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Aggressive optimizing Scheme compiler

BROKEN=		unfetchable

LIB_DEPENDS=	libgc.so:devel/boehm-gc

USES=	tar:bzip2
ONLY_FOR_ARCHS=	i386 amd64 sparc64
ONLY_FOR_ARCHS_REASON=	has not been bootstrapped on other platforms yet

OPTIONS_DEFINE=	DOCS

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

do-build:
	(cd ${WRKSRC} && ${CC} -o stalin -I${LOCALBASE}/include \
	    -L${LOCALBASE}/lib -lgc -lm ${CFLAGS} ${STALIN_SRC})
	ar -rc ${WRKSRC}/libstalin.a

do-install:
	@${MKDIR} ${STAGEDIR}${STALIN_LIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/stalin ${STAGEDIR}${STALIN_LIBDIR}
	(cd ${WRKSRC}/include && ${COPYTREE_SHARE} \* ${STAGEDIR}${STALIN_LIBDIR})
	${CHMOD} 755 ${STAGEDIR}${STALIN_LIBDIR}
	${CHMOD} a+x ${STAGEDIR}${STALIN_LIBDIR}/stalin-architecture-name
	${INSTALL_SCRIPT} ${WRKDIR}/stalin.sh ${STAGEDIR}${PREFIX}/bin/stalin
	${INSTALL_MAN} ${WRKSRC}/stalin.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/stalin.el ${STAGEDIR}${EMACSLISPDIR}
	${INSTALL_DATA} ${WRKSRC}/libstalin.a ${STAGEDIR}${STALIN_LIBDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
