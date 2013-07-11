# Created by: Thomas Dreibholz <dreibh@iem.uni-due.de>
# $FreeBSD$

PORTNAME=	bibtexconv
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://www.iem.uni-due.de/~dreibh/bibtexconv/download/ \
		http://www.exp-math.uni-essen.de/~dreibh/bibtexconv/download/

MAINTAINER=	dreibh@iem.uni-due.de
COMMENT=	BibTeX Converter

LICENSE=	GPLv3

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/bibtexconv bin/bibtexconv-odt
PORTEXAMPLES=	ExampleReferences.bib ODT-Template.odt odt-example.export \
		web-example.export text-example.export
MAN1=		bibtexconv.1 bibtexconv-odt.1

pre-configure:
	@${REINPLACE_CMD} -e 's|install-data-am: install-dist_examplesDATA|install-data-am:|' \
	${WRKSRC}/src/Makefile.in

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/src/${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
