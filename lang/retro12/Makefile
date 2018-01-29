# $FreeBSD$

PORTNAME=	retro12
DISTVERSION=	2018.1
CATEGORIES=	lang
MASTER_SITES=	https://forthworks.com/retro/r/
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Clean, elegant, and pragmatic dialect of Forth

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

PLIST_FILES=	bin/embedimage \
		bin/extend \
		bin/listener \
		bin/muri \
		bin/repl \
		bin/rre \
		bin/unu
PORTDATA=	glossary.forth \
		ngaImage \
		words.tsv

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	doc \
		literate \
		README.md \
		RELEASE_NOTES.md

PORTEXAMPLES=	example

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./build.sh

do-install:
.for f in embedimage extend muri repl rre unu
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/bin/listener ${STAGEDIR}${PREFIX}/bin/listener
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	cd ${WRKSRC} &&	${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	cd ${WRKSRC} &&	${COPYTREE_SHARE} "${PORTEXAMPLES}" ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
