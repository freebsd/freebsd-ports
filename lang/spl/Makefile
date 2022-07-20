PORTNAME=	spl
PORTVERSION=	1.2.1
PORTREVISION=	5
CATEGORIES=	lang
MASTER_SITES=	http://shakespearelang.sourceforge.net/download/

MAINTAINER=	fuz@fuz.su
COMMENT=	Shakespeare programming language

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison gmake

OPTIONS_DEFINE=	EXAMPLES

ALL_EXAMPLES=	Makefile fibonacci.spl fibonacci2.spl guess.spl hello.spl \
		primes.spl reverse.spl shakesbeer.spl

post-patch:
.for f in . examples
	${REINPLACE_CMD} -e 's,= gcc,?= gcc,' -e 's,^CCFLAGS.*,CFLAGS += -Wall,' \
		-e 's,CCFLAGS,CFLAGS,g' ${WRKSRC}/${f}/Makefile
.endfor
	${REINPLACE_CMD} -e 's,\(#define STRING_LENGTH\).*,\1 25600,g' \
		-e 's,free(,//free(,g' ${WRKSRC}/makescanner.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spl/bin/spl2c ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/spl/include/spl.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/spl/lib/libspl.a ${STAGEDIR}${PREFIX}/lib/
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && \
		${INSTALL_DATA} ${ALL_EXAMPLES} ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
