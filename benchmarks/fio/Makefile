# Created by: luigi@FreeBSD.org
# $FreeBSD$

PORTNAME=	fio
PORTVERSION=	2.0.15
CATEGORIES=	benchmarks
MASTER_SITES=	http://brick.kernel.dk/snaps/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	FIO - flexible IO tester

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
USE_GMAKE=	yes

OPTIONS_DEFINE=	GNUPLOT
GNUPLOT_DESC=	Support for plotting graphs

MAN1=		fio.1 fio_generate_plots.1

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fio ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/fio_generate_plots ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fio.1 ${MAN1PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/fio_generate_plots.1 ${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.if ${PORT_OPTIONS:MGNUPLOT}
BUILD_DEPENDS+=	${LOCALBASE}/bin/gnuplot:${PORTSDIR}/math/gnuplot
.endif

.include <bsd.port.mk>
