# Created by: Dima Sivachenko <dima@chg.ru>
# $FreeBSD$

PORTNAME=	polygraph31
PORTVERSION=	3.1.5
PORTREVISION=	3
CATEGORIES=	benchmarks www
MASTER_SITES=	http://www.web-polygraph.org/downloads/srcs/
DISTNAME=	${PORTNAME:S/31//}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	adrian@FreeBSD.org
COMMENT=	A benchmarking tool for Web proxies

GNU_CONFIGURE=	YES
CPPFLAGS+=	-Wno-deprecated
CONFIGURE_ARGS+=--datadir=${DATADIR}
WRKSRC=		${WRKDIR}/${PORTNAME:S/31//}-${PORTVERSION}

CONFLICTS=	ltrace-0* polygraph-[0-9]*

OPTIONS_DEFINE=	GNUPLOT PERL
OPTIONS_DEFAULT=	GNUPLOT
GNUPLOT_DESC=	gnuplot if you want full report functionality
PERL_DESC=	install Perl for polygraph tools

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 900009 || (${OSVERSION} < 900000 && ${OSVERSION} >= 800503)
BROKEN=		does not build
.endif

DATADIR:=	${DATADIR:S/31//}

.if ${PORT_OPTIONS:MGNUPLOT}
RUN_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
.endif

.if ${PORT_OPTIONS:MPERL}
USE_PERL5_RUN=	yes
.endif

.include <bsd.port.mk>
