# New ports collection makefile for:   ici
# Date created:        18 December 1997
# Whom:                andy
#
# $FreeBSD$
#

PORTNAME=	ici
PORTVERSION=	2.1.4
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.research.canon.com.au/pub/misc/ici/ \
		ftp://ftp.ntua.gr/pub/lang/ici/ \
		http://www.zeta.org.au/~atrn/ici/distfiles/

MAINTAINER=	andy@research.canon.com.au

MAKEFILE=	Makefile.bsd
MAN1=		ici.1
MANCOMPRESSED=	yes

ICIHDRS= alloc.h array.h buf.h catch.h conf-bsd.h exec.h file.h float.h \
	forall.h func.h fwd.h int.h mark.h mem.h null.h object.h op.h \
	parse.h pc.h primes.h ptr.h re.h set.h skt.h src.h str.h struct.h \
	trace.h win.h wrap.h

ICIPCREHDRS= pcre/internal.h pcre/pcre.h

ICIDOCS= doc/ici-a4.ps doc/ici-ltr.ps doc/ici.txt doc/ici.pdf

do-install:
	cd ${WRKSRC} && ${MAKE} -f ${MAKEFILE} libici.a
	${INSTALL_PROGRAM} ${WRKSRC}/ici ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libici.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/ici.1.gz ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/lib/ici
	${INSTALL_DATA} ${WRKSRC}/ici_init.ici ${PREFIX}/lib/ici
	${MKDIR} ${PREFIX}/include/ici
	${MKDIR} ${PREFIX}/include/ici/pcre
.for f in ${ICIHDRS}
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/include/ici
.endfor
.for f in ${ICIPCREHDRS}
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/include/ici/pcre
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ici
.for f in ${ICIDOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/share/doc/ici
.endfor
.endif

.include <bsd.port.mk>
