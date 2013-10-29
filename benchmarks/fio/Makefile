# Created by: luigi@FreeBSD.org
# $FreeBSD$

PORTNAME=	fio
PORTVERSION=	2.1.3
CATEGORIES=	benchmarks
MASTER_SITES=	http://brick.kernel.dk/snaps/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	FIO - flexible IO tester

LICENSE=	GPLv2

USES=		gmake
USE_BZIP2=	yes

OPTIONS_DEFINE=	GNUPLOT
GNUPLOT_DESC=	Support for plotting graphs

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fio ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/fio_generate_plots ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fio.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/tools/fio_generate_plots.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})
.endif

.if ${PORT_OPTIONS:MGNUPLOT}
BUILD_DEPENDS+=	${LOCALBASE}/bin/gnuplot:${PORTSDIR}/math/gnuplot
.endif

.include <bsd.port.mk>
