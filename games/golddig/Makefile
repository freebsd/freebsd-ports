DISTNAME=	golddig2
MASTER_SITES=	ftp://qiclab.scn.rain.com/pub/games/
CATEGORIES+=	games
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jmz@FreeBSD.org


pre-patch:
	@(cd ${WRKSRC}; for i in 245 244 246 247; do \
	    awk '{if (/^#!/) x++} {if(x) print $$0'} $$i| /bin/sh; \
	  done; mv golddig2/* .)

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/lib/golddig
	@mkdir -p ${PREFIX}/man/man6

.include <bsd.port.mk>
