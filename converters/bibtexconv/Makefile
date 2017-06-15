# Created by: Thomas Dreibholz <dreibh@iem.uni-due.de>
# $FreeBSD$

PORTNAME=	bibtexconv
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://www.iem.uni-due.de/~dreibh/bibtexconv/download/ \
		http://www.exp-math.uni-essen.de/~dreibh/bibtexconv/download/

MAINTAINER=	dreibh@iem.uni-due.de
COMMENT=	BibTeX Converter

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl

GNU_CONFIGURE=	yes
USES=		gmake

PLIST_FILES=	bin/bibtexconv bin/bibtexconv-odt \
		man/man1/bibtexconv.1.gz man/man1/bibtexconv-odt.1.gz

PORTEXAMPLES=	ExampleReferences.bib ODT-Template.odt odt-example.export \
		web-example.export text-example.export

OPTIONS_DEFINE=	EXAMPLES

pre-configure:
	@${REINPLACE_CMD} -e 's|install-data-am: install-dist_examplesDATA|install-data-am:|' \
	${WRKSRC}/src/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/src/,} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
