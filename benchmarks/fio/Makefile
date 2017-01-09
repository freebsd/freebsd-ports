# Created by: luigi@FreeBSD.org
# $FreeBSD$

PORTNAME=	fio
PORTVERSION=	2.16
CATEGORIES=	benchmarks
MASTER_SITES=	http://brick.kernel.dk/snaps/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	FIO - flexible IO tester

LICENSE=	GPLv2

USES=		gmake tar:bzip2

OPTIONS_DEFINE=	GNUPLOT EXAMPLES
GNUPLOT_DESC=	Support for plotting graphs

GNUPLOT_BUILD_DEPENDS=	${LOCALBASE}/bin/gnuplot:math/gnuplot

BROKEN_powerpc64=	Does not build on powerpc64

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fio ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/fio_generate_plots ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fio.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/tools/fio_generate_plots.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
