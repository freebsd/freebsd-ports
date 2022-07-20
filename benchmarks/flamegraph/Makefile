PORTNAME=	flamegraph
PORTVERSION=	1.1
CATEGORIES=	benchmarks

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Stack trace visualizer

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/docs/cddl1.txt

BUILD_DEPENDS=	bash>=0:shells/bash
RUN_DEPENDS=	bash>=0:shells/bash

USES=		shebangfix perl5 python

USE_GITHUB=	yes
GH_ACCOUNT=	brendangregg
GH_PROJECT=	FlameGraph
GH_TAGNAME=	810687f

NO_BUILD=	yes

CONFLICTS_INSTALL=	p5-Devel-NYTProf

SHEBANG_FILES=	*.php *.pl *.py *.sh

SOURCE_FILES=	aix-perf.pl \
		difffolded.pl \
		files.pl \
		flamegraph.pl \
		pkgsplit-perf.pl \
		range-perf.pl \
		stackcollapse-aix.pl \
		stackcollapse-bpftrace.pl \
		stackcollapse-chrome-tracing.py \
		stackcollapse-elfutils.pl \
		stackcollapse-gdb.pl \
		stackcollapse-go.pl \
		stackcollapse-instruments.pl \
		stackcollapse-java-exceptions.pl \
		stackcollapse-jstack.pl \
		stackcollapse-ljp.awk \
		stackcollapse-perf-sched.awk \
		stackcollapse-perf.pl \
		stackcollapse-pmc.pl \
		stackcollapse-recursive.pl \
		stackcollapse-sample.awk \
		stackcollapse-stap.pl \
		stackcollapse-vsprof.pl \
		stackcollapse-vtune.pl \
		stackcollapse-xdebug.php \
		stackcollapse.pl

do-install:
.for FILE in ${SOURCE_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${STAGEDIR}/${PREFIX}/bin/${FILE}
.endfor

.include <bsd.port.mk>
