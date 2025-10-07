PORTNAME=	opentimer
DISTVERSION=	2.1.0-20250707
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance timing analysis tool for VLSI systems
WWW=		https://github.com/OpenTimer/OpenTimer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang python:test shebangfix tcl

USE_GITHUB=	yes
GH_ACCOUNT=	OpenTimer
GH_PROJECT=	OpenTimer
GH_TAGNAME=	8c76916c

SHEBANG_FILES=	inttest/*.py

TEST_TARGET=	test

PLIST_FILES=	bin/ot-shell \
		bin/ot-tau15 \
		bin/ot-tau18 \
		bin/ot-utility
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

do-install: # see https://github.com/OpenTimer/OpenTimer/issues/47
.for e in ot-shell ot-tau15 ot-tau18 ot-utility
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${e} \
		${STAGEDIR}${PREFIX}/bin
.endfor

post-install-DOCS-on:
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} "doc wiki" ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/example && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
.for e in fcpc26 incremental optimizer simple sizer unit
	${STRIP_CMD} ${STAGEDIR}${EXAMPLESDIR}/${e}/${e}
.endfor

quick-test: # runs the script suggested in https://github.com/OpenTimer/OpenTimer
	@cd ${WRKSRC} && \
		bin/ot-shell < ${FILESDIR}/test.txt

.include <bsd.port.mk>
