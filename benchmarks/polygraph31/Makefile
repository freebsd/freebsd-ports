# New ports collection makefile for:	polygraph
# Date created:         3 March 1999
# Whom:                 Dima Sivachenko <dima@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	polygraph31
PORTVERSION=	3.1.5
PORTREVISION=	2
CATEGORIES=	benchmarks www
MASTER_SITES=	http://www.web-polygraph.org/downloads/srcs/
DISTNAME=	${PORTNAME:S/31//}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	adrian@freebsd.org
COMMENT=	A benchmarking tool for Web proxies

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -Wno-deprecated"
CONFIGURE_ARGS+=--datadir=${DATADIR}
WRKSRC=		${WRKDIR}/${PORTNAME:S/31//}-${PORTVERSION}

CONFLICTS=	ltrace-0* polygraph-[0-9]*

OPTIONS=	GNUPLOT "gnuplot if you want full report functionality" ON \
		PERL	"install Perl for polygraph tools"		OFF

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900009 || (${OSVERSION} < 900000 && ${OSVERSION} >= 800503)
BROKEN=		does not build
.endif

DATADIR:=	${DATADIR:S/31//}

.if !defined(WITHOUT_GNUPLOT)
RUN_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
.endif

.if !defined(WITHOUT_PERL)
USE_PERL5_RUN=	yes
.endif

.include <bsd.port.post.mk>
