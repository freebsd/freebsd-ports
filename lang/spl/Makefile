# New ports collection makefile for:	spl
# Date created:		6 September 2001
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	spl
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://shakespearelang.sourceforge.net/download/

MAINTAINER=	perky@FreeBSD.org
COMMENT=	The Shakespeare programming language

USE_BISON=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

ALL_EXAMPLES=	Makefile fibonacci.spl fibonacci2.spl guess.spl hello.spl \
		primes.spl reverse.spl shakesbeer.spl

post-patch:
	@for f in ${WRKSRC}/Makefile ${WRKSRC}/examples/Makefile; do \
	 ${REINPLACE_CMD} -i "" -e 's,= gcc,?= gcc,' -e 's,^CCFLAGS.*,CFLAGS += -Wall,' \
		-e 's,CCFLAGS,CFLAGS,g' -e 's,^SPLPATH =.*,SPLPATH =${PREFIX},g' \
		-e 's, spl/, ${PREFIX}/,g' $$f; \
	done

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_DATA} ${ALL_EXAMPLES} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
