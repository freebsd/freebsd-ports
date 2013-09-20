# Created by: Cyrille Lefevre <clefevre@citeweb.net>
# $FreeBSD$

PORTNAME=	gengetopt
PORTVERSION=	2.22.6
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Tool for generating a C function which parses command line arguments

LICENSE=	GPLv3

INSTALL_WRKSRC=	${WRKSRC}/src

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes

CFLAGS+=	-D_GL_SYSTEM_GETOPT

MAN1=		gengetopt.1
INFO=		gengetopt

PLIST_FILES=	bin/gengetopt %%DATADIR%%/getopt.c %%DATADIR%%/getopt1.c \
		%%DATADIR%%/gnugetopt.h

PLIST_DIRS=	%%DATADIR%%

PORTDOCS=	*
PORTEXAMPLES=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog NEWS README THANKS TODO

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	index.html gengetopt.html

DOC_EXAMPLES=	README.example cmdline1.c cmdline1.h cmdline2.c cmdline2.h \
		main1.cc main2.c multiple_example.c sample1.ggo sample2.ggo
TESTS_EXAMPLES=	test_manual_help.c test_manual_help_cmd.c \
		test_manual_help_cmd.ggo test_manual_help_cmd.h

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${MAN1PREFIX}/man/man1
	${MKDIR} ${PREFIX}/${INFO_PATH}
	${INSTALL_DATA} ${WRKSRC}/doc/${INFO}.info ${PREFIX}/${INFO_PATH}

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
.for e in ${DOC_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/doc/${e} ${EXAMPLESDIR}
.endfor
.for e in ${TESTS_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/tests/${e} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
