# Created by: ijliao
# $FreeBSD$

PORTNAME=	autobench
PORTVERSION=	2.1.2
PORTREVISION=	8
CATEGORIES=	benchmarks www
MASTER_SITES=	http://www.xenoclast.org/autobench/downloads/ \
		http://www.sfr-fresh.com/unix/privat/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automating the process of benchmarking a web server

RUN_DEPENDS=	httperf:${PORTSDIR}/benchmarks/httperf \
		gawk:${PORTSDIR}/lang/gawk \
		gnuplot:${PORTSDIR}/math/gnuplot

LICENSE=	GPLv2

USES=		gmake perl5 shebangfix
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" DEBUG_FLAGS= \
		PREFIX=${PREFIX}
SHEBANG_FILES= 	autobench_admin autobenchd autobench

post-patch:
.for file in autobench autobench_admin
	@${REINPLACE_CMD} -i '' -e 's|/etc/|${PREFIX}/etc/|' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
