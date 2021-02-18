# $FreeBSD$

PORTNAME=	retro12
DISTVERSION=	2021.2
CATEGORIES=	lang
MASTER_SITES=	http://forthworks.com/retro/r/ \
		https://forthworks.com/retro/r/
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clean, elegant, and pragmatic dialect of Forth

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		shebangfix
USE_CSTD=	c99

SHEBANG_FILES=	example/Atua*
SHEBANG_LANG=	retro

MAKE_ENV=	DATADIR=${DATADIR} \
		DESTDIR=${DESTDIR} \
		DOCSDIR=${DOCSDIR} \
		EXAMPLESDIR=${EXAMPLESDIR} \
		PREFIX=${PREFIX}
# There are race conditions in the makefile due to missing dependencies for
# targets as upstream tests releases on single core machines.
MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	test

PLIST_FILES=	bin/retro \
		bin/retro-describe \
		bin/retro-document \
		bin/retro-embedimage \
		bin/retro-extend \
		bin/retro-locate \
		bin/retro-muri \
		bin/retro-tags \
		bin/retro-unu

PORTDATA=	glossary.retro ngaImage tests words.tsv

PORTDOCS=	README RELEASE-NOTES RETRO-Book.md words.tsv

PORTEXAMPLES=	example

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.mk>
