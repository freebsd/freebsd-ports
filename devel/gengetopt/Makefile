PORTNAME=	gengetopt
PORTVERSION=	2.23
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tool for generating a C function which parses command line arguments
WWW=		https://www.gnu.org/software/gengetopt/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		makeinfo tar:xz

GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=yes

CFLAGS+=	-D_GL_SYSTEM_GETOPT

INSTALL_WRKSRC=	${WRKSRC}/src

INFO=		gengetopt
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

DOC_EXAMPLES=	README.example cmdline1.c cmdline1.h cmdline2.c cmdline2.h \
		main1.cc main2.c multiple_example.c sample1.ggo sample2.ggo
TESTS_EXAMPLES=	test_manual_help.c test_manual_help_cmd.c \
		test_manual_help_cmd.ggo test_manual_help_cmd.h

.include <bsd.port.options.mk>

post-patch:
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
	@${REINPLACE_CMD} -e 's|std::unary_function|std::__unary_function|' \
		${WRKSRC}/src/gm_utils.h
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/
	@${MKDIR} ${STAGEDIR}${PREFIX}/${INFO_PATH}
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog NEWS \
		README THANKS TODO doc/index.html doc/gengetopt.html \
		${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for e in ${DOC_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/doc/${e} ${STAGEDIR}${EXAMPLESDIR}
.endfor
.for e in ${TESTS_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/tests/${e} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
