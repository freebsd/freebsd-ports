# Created by: Johannes Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flamegraph
PORTVERSION=	g20170308
PORTREVISION=	1
CATEGORIES=	benchmarks

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Stack trace visualizer

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/docs/cddl1.txt

BUILD_DEPENDS=	bash>=0:shells/bash
RUN_DEPENDS=	bash>=0:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	brendangregg
GH_PROJECT=	FlameGraph
GH_TAGNAME=	74764af

USES=		shebangfix perl5
NO_BUILD=	yes

SHEBANG_FILES=	*.pl *.sh

SOURCE_FILES=	aix-perf.pl \
		difffolded.pl \
		files.pl \
		flamegraph.pl \
		pkgsplit-perf.sh \
		range-perf.pl \
		stackcollapse-aix.pl \
		stackcollapse-elfutils.pl \
		stackcollapse-gdb.pl \
		stackcollapse-go.pl \
		stackcollapse-instruments.pl \
		stackcollapse-jstack.pl \
		stackcollapse-ljp.awk \
		stackcollapse-perf.pl \
		stackcollapse-pmc.pl \
		stackcollapse-recursive.pl \
		stackcollapse-stap.pl \
		stackcollapse-vtune.pl \
		stackcollapse.pl

do-install:
.for FILE in ${SOURCE_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${STAGEDIR}/${PREFIX}/bin/${FILE}
.endfor

.include <bsd.port.mk>
