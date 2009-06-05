# ex:ts=8
# Ports collection makefile for:	autobench
# Date created:			Oct 20, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	autobench
PORTVERSION=	2.1.2
PORTREVISION=	2
CATEGORIES=	benchmarks www
MASTER_SITES=	http://www.xenoclast.org/autobench/downloads/ \
		http://www.sfr-fresh.com/unix/privat/

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Automating the process of benchmarking a web server

RUN_DEPENDS=	httperf:${PORTSDIR}/benchmarks/httperf \
		gawk:${PORTSDIR}/lang/gawk \
		gnuplot:${PORTSDIR}/math/gnuplot

USE_PERL5=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" DEBUG_FLAGS= \
		PREFIX=${PREFIX}

MAN1=	autobench.1 autobench_admin.1 autobenchd.1 bench2graph.1 \
	crfile.1 sesslog.1

post-patch:
.for file in autobench autobench_admin
	@${PERL} -pi -e "s|/etc/|${PREFIX}/etc/|g" ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
