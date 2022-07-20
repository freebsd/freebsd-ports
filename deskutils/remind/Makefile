PORTNAME=	remind
DISTVERSION=	04.00.01
CATEGORIES=	deskutils
# upstream moves distfiles to OLD once a new release appears
MASTER_SITES=	https://dianne.skoll.ca/projects/remind/download/ \
		https://dianne.skoll.ca/projects/remind/download/OLD/

MAINTAINER=	fuz@fuz.su
COMMENT=	Sophisticated calendar and alarm program

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-perl-build-artifacts
MAKE_ARGS=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
INSTALL_TARGET=	${WITH_DEBUG:Dinstall-nostripped:Uinstall}

OPTIONS_DEFINE=	A4 TCLTK REM2HTML REM2PDF
OPTIONS_DEFAULT=	LANG_US REM2HTML REM2PDF
OPTIONS_SINGLE=	LANGUAGE
OPTIONS_SINGLE_LANGUAGE=	LANG_US LANG_DE LANG_NL LANG_FI LANG_FR \
				LANG_NN LANG_DA LANG_PL LANG_PBR LANG_IT \
				LANG_RO LANG_ES LANG_IS
OPTIONS_SUB=	yes
A4_DESC=	Use A4 instead of Letter paper
LANGUAGE_DESC=	User interface language
REM2HTML_DESC=	Build and install rem2html (requires Perl)
REM2PDF_DESC=	Build and install rem2pdf (requires Perl)

# do not sort these -- correspond to enumeration in source code
LANG.US=	ENGLISH
LANG.DE=	GERMAN
LANG.NL=	DUTCH
LANG.FI=	FINNISH
LANG.FR=	FRENCH
LANG.NN=	NORWEGIAN
LANG.DA=	DANISH
LANG.PL=	POLISH
LANG.PBR=	BRAZPORT
LANG.IT=	ITALIAN
LANG.RO=	ROMANIAN
LANG.ES=	SPANISH
LANG.IS=	ICELANDIC
CFLAGS+=	-DLANG=${${PORT_OPTIONS:MLANG_*:S/_/./}}

TCLTK_USES=	tk
TCLTK_RUN_DEPENDS=	dtplite:devel/tcllib

REM2HTML_USES=	perl5
REM2HTML_RUN_DEPENDS=	p5-JSON-MaybeXS>0:converters/p5-JSON-MaybeXS

REM2PDF_USES=	perl5
REM2PDF_RUN_DEPENDS=	p5-Cairo>0:graphics/p5-Cairo \
			p5-Pango>0:x11-toolkits/p5-Pango

# hard wired customisation variables
DEFAULT_LATITUDE?=	45.42055555555555
DEFAULT_LONGITUDE?=	-75.68972222222223
LOCATION?=	Ottawa

post-patch:
	@${REINPLACE_CMD} \
	    -e 's#DEFAULT_LATITUDE 39#DEFAULT_LATITUDE ${DEFAULT_LATITUDE}#' \
	    -e 's#DEFAULT_LONGITUDE 39#DEFAULT_LONGITUDE ${DEFAULT_LONGITUDE}#' \
	    -e 's#Ottawa#${LOCATION}#' ${WRKSRC}/src/custom.h

post-patch-A4-on:
	@${REINPLACE_CMD} -e 's#"Letter", 612, 792#"A4", 595, 842#' ${WRKSRC}/src/custom.h

post-patch-TCLTK-on:
	@${REINPLACE_CMD} -e 's,wish,${WISH},' ${WRKSRC}/scripts/tkremind

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} all

do-install:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}

do-install-REM2HTML-on:
	cd ${WRKSRC}/rem2html && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install

do-install-REM2PDF-on:
	cd ${WRKSRC}/rem2pdf && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} Makefile.top ${MAKE_ARGS} all
	cd ${WRKSRC}/rem2pdf && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} Makefile.top ${MAKE_ARGS} install

post-install-TCLTK-off:
	${RM} ${STAGEDIR}${PREFIX}/bin/tkremind
	${RM} ${STAGEDIR}${PREFIX}/man/man1/tkremind.1

.include <bsd.port.mk>
