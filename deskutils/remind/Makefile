# Created by: Lewis Thompson <purple@lewiz.net>

PORTNAME=	remind
DISTVERSION=	03.03.11
CATEGORIES=	deskutils
MASTER_SITES=	https://dianne.skoll.ca/projects/remind/download/

MAINTAINER=	fuz@fuz.su
COMMENT=	Sophisticated calendar and alarm program

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
MAKE_ARGS=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
INSTALL_TARGET=	${WITH_DEBUG:Dinstall-nostripped:Uinstall}

PLIST_FILES=	bin/rem \
		bin/rem2ps \
		bin/remind \
		man/man1/rem.1.gz \
		man/man1/rem2ps.1.gz \
		man/man1/remind.1.gz

OPTIONS_DEFINE=	A4 TCLTK REM2HTML
OPTIONS_DEFAULT=	LANG_US REM2HTML
OPTIONS_SINGLE=	LANGUAGE
OPTIONS_SINGLE_LANGUAGE= \
		LANG_US LANG_DE LANG_NL LANG_FI LANG_FR LANG_NN LANG_DA \
		LANG_PL LANG_PBR LANG_IT LANG_RO LANG_ES LANG_IS
A4_DESC=	Use A4 instead of Letter paper
LANGUAGE_DESC=	User interface language
REM2HTML_DESC=	Build and install rem2html (requires Perl)

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

TCLTK_USES=	tk
TCLTK_RUN_DEPENDS=	dtplite:devel/tcllib
TCLTK_PLIST_FILES=	bin/tkremind \
			man/man1/tkremind.1.gz
REM2HTML_USES=	perl5
REM2HTML_BUILD_DEPENDS=	p5-JSON-Any>0:converters/p5-JSON-Any
REM2HTML_RUN_DEPENDS=	p5-JSON-Any>0:converters/p5-JSON-Any
REM2HTML_PLIST_FILES=	bin/rem2html

# hard wired customisation variables
LAT_DEG?=	45
LAT_MIN?=	24
LAT_SEC?=	0
LON_DEG?=	75
LON_MIN?=	39
LON_SEC?=	0
LOCATION?=	Ottawa

CFLAGS+=	-DLANG=${${PORT_OPTIONS:MLANG_*:S/_/./}}

post-patch:
	@${REINPLACE_CMD} \
	    -e 's#LAT_DEG 45#LAT_DEG ${LAT_DEG}#' \
	    -e 's#LAT_MIN 24#LAT_MIN ${LAT_MIN}#' \
	    -e 's#LAT_SEC  0#LAT_SEC ${LAT_SEC}#' \
	    -e 's#LON_DEG 75#LON_DEG ${LON_DEG}#' \
	    -e 's#LON_MIN 39#LON_MIN ${LON_MIN}#' \
	    -e 's#LON_SEC  0#LON_SEC ${LON_SEC}#' \
	    -e 's#Ottawa#${LOCATION}#' ${WRKSRC}/src/custom.h

post-patch-A4-on:
	@${REINPLACE_CMD} -e 's#"Letter", 612, 792#"A4", 595, 842#' ${WRKSRC}/src/custom.h

post-patch-TCLTK-on:
	@${REINPLACE_CMD} -e 's,wish,${WISH},' ${WRKSRC}/scripts/tkremind

do-install:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}

do-install-REM2HTML-on:
	cd ${WRKSRC}/rem2html && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install

post-install-TCLTK-off:
	${RM} ${STAGEDIR}${PREFIX}/bin/tkremind
	${RM} ${STAGEDIR}${PREFIX}/man/man1/tkremind.1

.include <bsd.port.mk>
