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

ALL_EXAMPLES=	Makefile fibonacci.spl fibonacci2.spl guess.spl hello.spl \
		primes.spl reverse.spl shakesbeer.spl

post-patch:
	@${PERL} -pi -e 's,= gcc,?= gcc,; s,^CCFLAGS.*,CFLAGS += -Wall,; \
		s,CCFLAGS,CFLAGS,g' \
		${WRKSRC}/Makefile ${WRKSRC}/examples/Makefile

do-install:
	${TAR} -C ${WRKSRC}/spl -cf- . | ${TAR} -C ${PREFIX} -xpf-
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_DATA} ${ALL_EXAMPLES} ${EXAMPLESDIR}
	@${PERL} -pi -e 's,^SPLPATH =.*,SPLPATH =${PREFIX},g' \
		${EXAMPLESDIR}/Makefile
.endif

.include <bsd.port.mk>
