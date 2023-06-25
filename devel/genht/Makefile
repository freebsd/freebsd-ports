PORTNAME=	genht
DISTVERSION=	1.1.3
CATEGORIES=	devel
MASTER_SITES=	http://www.repo.hu/projects/genht/releases/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Simple generic hash table implementation in C
WWW=		http://www.repo.hu/projects/genht/

LICENSE=	PD

USES=		tar:bz2
USE_LDCONFIG=	yes

MAKE_ARGS+=	GENHT_CFLAGS='${CFLAGS}' \
		GENHT_LDFLAGS='${STRIP} ${LDFLAGS}' \
		PREFIX=${PREFIX}

PORTEXAMPLES=	Makefile example.c examplev.c

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/doc/$f ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
