# Created by: Thomas Dreibholz <dreibh@iem.uni-due.de>
# $FreeBSD$

PORTNAME=	bibtexconv
PORTVERSION=	1.1.11
CATEGORIES=	converters
MASTER_SITES=	https://www.uni-due.de/~be0001/bibtexconv/download/

MAINTAINER=	dreibh@iem.uni-due.de
COMMENT=	BibTeX Converter

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.GPL

LIB_DEPENDS=	libcurl.so:ftp/curl

GNU_CONFIGURE=	yes
USES=		gmake ssl python:3.4+

PLIST_FILES=	bin/bibtexconv bin/bibtexconv-odt bin/ietf2bibtex \
		man/man1/bibtexconv.1.gz man/man1/bibtexconv-odt.1.gz \
		man/man1/ietf2bibtex.1.gz

PORTEXAMPLES=	ExampleReferences.bib ODT-Template.odt odt-example.export \
		web-example.export text-example.export

OPTIONS_DEFINE=	EXAMPLES

pre-configure:
	@${REINPLACE_CMD} -e 's|install-data-am: install-dist_examplesDATA|install-data-am:|' \
	${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/bin/python3|${PYTHON_CMD}|' ${WRKSRC}/src/ietf2bibtex

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/src/,} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
