# New ports collection makefile for:   ici
# Date created:        18 December 1997
# Whom:                andy
#
# $FreeBSD$
#

PORTNAME=	ici
PORTVERSION=	3.0.1
CATEGORIES=	lang
MASTER_SITES=	http://www.zeta.org.au/~atrn/ici/distfiles/

MAINTAINER=	atrn@zeta.org.au
COMMENT=	An interpretive language with C's overall feel combined with high level data types

MAKEFILE=	Makefile.bsd
MAN1=		ici3.1
MANCOMPRESSED=	yes

USE_REINPLACE=	yes
USE_BZIP2=	yes

ICIHDRS=	alloc.h array.h buf.h catch.h cfunc.h conf-bsd.h exec.h file.h \
		float.h forall.h func.h fwd.h ici.h int.h mark.h mem.h \
		method.h null.h object.h op.h parse.h pc.h primes.h ptr.h re.h \
		set.h skt.h src.h str.h struct.h trace.h win.h wrap.h

ICIPCREHDRS=	pcre/internal.h pcre/pcre.h

ICIDOCS=	doc/ici-a4.ps doc/ici-ltr.ps doc/ici.txt doc/ici.pdf

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

post-patch:
	${REINPLACE_CMD} -e 's/float_t/floats_t/g' ${WRKSRC}/*.[ch]

do-install:
	cd ${WRKSRC} && ${MAKE} -f ${MAKEFILE} libici3.a
	${INSTALL_PROGRAM} ${WRKSRC}/ici3 ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libici3.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/ici3.1.gz ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/lib/ici3
	${INSTALL_DATA} ${WRKSRC}/ici3core.ici ${PREFIX}/lib/ici3
	${INSTALL_DATA} ${WRKSRC}/ici3core1.ici ${PREFIX}/lib/ici3
	${INSTALL_DATA} ${WRKSRC}/ici3core2.ici ${PREFIX}/lib/ici3
	${INSTALL_DATA} ${WRKSRC}/ici3core3.ici ${PREFIX}/lib/ici3
	${MKDIR} ${PREFIX}/include/ici3
	${MKDIR} ${PREFIX}/include/ici3/pcre
.for f in ${ICIHDRS}
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/include/ici3
.endfor
.for f in ${ICIPCREHDRS}
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/include/ici3/pcre
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ici3
.for f in ${ICIDOCS}
	${INSTALL_MAN} ${WRKSRC}/$f ${PREFIX}/share/doc/ici3
.endfor
.endif

.include <bsd.port.post.mk>
