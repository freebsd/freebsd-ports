DISTNAME=	mtools-2.0.7
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/
CATEGORIES+=	utilities
MAINTAINER=	jmz@FreeBSD.org

MAKE_FLAGS=	PREFIX=${PREFIX}
MAKEFILE=

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/man/man1

.include <bsd.port.mk>
