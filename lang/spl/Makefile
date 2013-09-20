# Created by: Hye-Shik Chang <perky@fallin.lv>
# $FreeBSD$

PORTNAME=	spl
PORTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://shakespearelang.sourceforge.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Shakespeare programming language

USES=		bison
USE_GMAKE=	yes

ALL_EXAMPLES=	Makefile fibonacci.spl fibonacci2.spl guess.spl hello.spl \
		primes.spl reverse.spl shakesbeer.spl

NO_STAGE=	yes
post-patch:
.for f in . examples
	${REINPLACE_CMD} -e 's,= gcc,?= gcc,' -e 's,^CCFLAGS.*,CFLAGS += -Wall,' \
		-e 's,CCFLAGS,CFLAGS,g' ${WRKSRC}/${f}/Makefile
.endfor
	${REINPLACE_CMD} -e 's,\(#define STRING_LENGTH\).*,\1 25600,g' \
		-e 's,free(,//free(,g' ${WRKSRC}/makescanner.c

do-install:
	${TAR} -C ${WRKSRC}/spl -cf - . | ${TAR} -C ${PREFIX} -xf -
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_DATA} ${ALL_EXAMPLES} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
