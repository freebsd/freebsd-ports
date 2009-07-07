# ex:ts=8
# New ports collection makefile for:	gengetopt
# Date created:				12 October 2000
# Whom:					Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	gengetopt
PORTVERSION=	2.22.2
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	corky1951@comcast.net
COMMENT=	A tool for generating a C function which parses command line arguments

INSTALL_WRKSRC=	${WRKSRC}/src

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		gengetopt.1
INFO=		gengetopt
PORTDOCS=	${ROOT_DOCS} ${DOC_DOCS}
PORTEXAMPLES=	${DOC_EXAMPLES} ${TESTS_EXAMPLES}
PLIST_FILES=	bin/gengetopt %%DATADIR%%/getopt.c %%DATADIR%%/getopt1.c \
		%%DATADIR%%/gnugetopt.h
PLIST_DIRS=	%%DATADIR%%

ROOT_DOCS=	AUTHORS ChangeLog LICENSE NEWS README THANKS TODO
DOC_DOCS=	index.html gengetopt.html
DOC_EXAMPLES=	README.example cmdline1.c cmdline1.h cmdline2.c cmdline2.h \
		main1.cc main2.c sample1.ggo sample2.ggo
TESTS_EXAMPLES=	test_manual_help.c test_manual_help_cmd.c \
		test_manual_help_cmd.ggo test_manual_help_cmd.h

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/gengetopt.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc/gengetopt.info ${PREFIX}/${INFO_PATH}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${ROOT_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.for file in ${DOC_DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${DOC_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${EXAMPLESDIR}
.endfor
.for file in ${TESTS_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/tests/${file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
