# New ports collection makefile for:	spl
# Date created:		6 September 2001
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	spl
PORTVERSION=	1.2.1
CATEGORIES=	lang
MASTER_SITES=	http://shakespearelang.sourceforge.net/download/

MAINTAINER=	perky@fallin.lv

USE_BISON=	yes
USE_GMAKE=	yes

ALL_TARGET=	spl2c libspl.a
ALL_EXAMPLES=	Makefile fibonacci.spl fibonacci2.spl guess.spl hello.spl \
		primes.spl reverse.spl shakesbeer.spl

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 500036
	@${PERL} -pi -e 's,= gcc,?= gcc,; s,^CCFLAGS.*,CFLAGS += -Wall,; \
		s,CCFLAGS,CFLAGS,g; s,^SPLPATH =.*,SPLPATH =${PREFIX},g; \
		s, spl/, ${PREFIX}/,g;' \
		${WRKSRC}/Makefile ${WRKSRC}/examples/Makefile
.else
	@for f in ${WRKSRC}/Makefile ${WRKSRC}/examples/Makefile; do \
	  ${SED} -i "" -e 's,= gcc,?= gcc,' -e 's,^CCFLAGS.*,CFLAGS += -Wall,' \
		-e 's,CCFLAGS,CFLAGS,g' -e 's,^SPLPATH =.*,SPLPATH =${PREFIX},g' \
		-e 's, spl/, ${PREFIX}/,g' $$f; \
	done
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_DATA} ${ALL_EXAMPLES} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
