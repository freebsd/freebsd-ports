# Created by: Cyrille Lefevre <clefevre@citeweb.net>
# $FreeBSD$

PORTNAME=	gengetopt
PORTVERSION=	2.22.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Tool for generating a C function which parses command line arguments

LICENSE=	GPLv3

INSTALL_WRKSRC=	${WRKSRC}/src

USES=		gmake
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes

CFLAGS+=	-D_GL_SYSTEM_GETOPT

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

.include <bsd.port.options.mk>

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/
	@${MKDIR} ${STAGEDIR}${PREFIX}/${INFO_PATH}
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for e in ${DOC_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/doc/${e} ${STAGEDIR}${EXAMPLESDIR}
.endfor
.for e in ${TESTS_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/tests/${e} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
