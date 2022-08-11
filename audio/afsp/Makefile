PORTNAME=	afsp
PORTVERSION=	8.2
CATEGORIES=	audio
MASTER_SITES=	http://www-mmsp.ece.mcgill.ca/Documents/Downloads/AFsp/
DISTNAME=	AFsp-v8r2

MAINTAINER=	ginga-freebsd@ginganet.org
COMMENT=	Audio file conversion utilities and library

USES=		gmake
MAKE_JOBS_UNSAFE=	yes

MAKE_ARGS=	COPTS="${CFLAGS}"

post-extract:
	@${CP} -f ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
