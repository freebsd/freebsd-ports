PORTNAME=	libowfat
PORTVERSION=	0.33
CATEGORIES=	devel
MASTER_SITES=	https://www.fefe.de/libowfat/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	General purpose library based on code by D. J. Bernstein
WWW=		https://www.fefe.de/libowfat/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake tar:xz

#ALL_TARGET=	headers
#ALL_TARGET=	havealloca.h iopause.h headers all
#CFLAGS+=	-fPIC
#MAKE_ENV=	DIET=
MAKEFILE=	GNUmakefile
#MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=OPTIMIZED_CFLAGS

OPTIMIZED_CFLAGS_CFLAGS=	-O2 -fomit-frame-pointer

pre-build:
	@cd ${WRKSRC} && ${DO_MAKE_BUILD} headers

post-install:
	cd ${STAGEDIR}${PREFIX}/share/man/man3 && ${FIND} * -name '*.3' -exec ${MV} {} libowfat_{} \;

.include <bsd.port.mk>
