# Created by: Johannes Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flamegraph
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0-43
DISTVERSIONSUFFIX=	-ga258e78
CATEGORIES=	benchmarks

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Stack trace visualizer

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/docs/cddl1.txt

BUILD_DEPENDS=	bash>=0:shells/bash
RUN_DEPENDS=	bash>=0:shells/bash

USES=		shebangfix perl5

USE_GITHUB=	yes
GH_ACCOUNT=	brendangregg
GH_PROJECT=	FlameGraph

NO_BUILD=	yes

SHEBANG_FILES=	*.pl *.sh

SOURCE_FILES=	aix-perf.pl \
		difffolded.pl \
		files.pl \
		flamegraph.pl \
		pkgsplit-perf.pl \
		range-perf.pl \
		stackcollapse-aix.pl \
		stackcollapse-bpftrace.pl \
		stackcollapse-elfutils.pl \
		stackcollapse-gdb.pl \
		stackcollapse-go.pl \
		stackcollapse-instruments.pl \
		stackcollapse-java-exceptions.pl \
		stackcollapse-jstack.pl \
		stackcollapse-ljp.awk \
		stackcollapse-perf.pl \
		stackcollapse-pmc.pl \
		stackcollapse-recursive.pl \
		stackcollapse-stap.pl \
		stackcollapse-vsprof.pl \
		stackcollapse-vtune.pl \
		stackcollapse.pl

do-install:
.for FILE in ${SOURCE_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${STAGEDIR}/${PREFIX}/bin/${FILE}
.endfor

.include <bsd.port.mk>
