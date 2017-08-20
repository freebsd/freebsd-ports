# Created by: luigi@FreeBSD.org
# $FreeBSD$

PORTNAME=	fio
PORTVERSION=	3.0
CATEGORIES=	benchmarks
MASTER_SITES=	http://brick.kernel.dk/snaps/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	FIO - flexible IO tester

LICENSE=	GPLv2

USES=		gmake tar:bzip2

OPTIONS_DEFINE=	GNUPLOT EXAMPLES
GNUPLOT_DESC=	Support for plotting graphs

GNUPLOT_BUILD_DEPENDS=	${LOCALBASE}/bin/gnuplot:math/gnuplot

BROKEN_aarch64=		Fails to compile: error: sys/auxv.h file not found
BROKEN_armv6=		Fails to compile: error: use of undeclared identifier nop
BROKEN_powerpc64=	Fails to compile: verify.c:1574: undefined reference to bswap64

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fio ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/fio_generate_plots ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fio.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/tools/fio_generate_plots.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
