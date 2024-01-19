PORTNAME=	cpipe
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	BERLIOS

MAINTAINER=	chris@uminac.com
COMMENT=	Benchmarking tool for pipes

LICENSE=	GPLv2

MAKEFILE=	makefile
ALL_TARGET=	# nada
MAKE_ARGS=	"prefix=${PREFIX}"

PLIST_FILES=	bin/cpipe share/man/man1/cpipe.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
