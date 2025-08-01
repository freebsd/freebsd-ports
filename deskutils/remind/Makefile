PORTNAME=	remind
DISTVERSION=	05.05.00
CATEGORIES=	deskutils
# upstream moves distfiles to OLD once a new release appears
MASTER_SITES=	https://dianne.skoll.ca/projects/remind/download/ \
		https://dianne.skoll.ca/projects/remind/download/OLD/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Sophisticated calendar and alarm program
WWW=		https://dianne.skoll.ca/projects/remind/

LICENSE=	GPLv2

USES=		autoreconf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-perl-build-artifacts
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
MAKE_ARGS=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
INSTALL_TARGET=	${WITH_DEBUG:Dinstall:Uinstall-stripped}
TEST_TARGET=	test
MAKE_JOBS_UNSAFE=	yes
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}

# disable LTO on riscv64
EXTRA_PATCHES_riscv64=	${FILESDIR}/extra-patch-configure.in
EXTRA_PATCHES=	${EXTRA_PATCHES_${ARCH}}

OPTIONS_DEFINE=	A4 TCLTK REM2HTML REM2PDF
OPTIONS_DEFAULT=	REM2HTML REM2PDF
OPTIONS_SUB=	yes
A4_DESC=	Use A4 instead of Letter paper
REM2HTML_DESC=	Build and install rem2html (requires Perl)
REM2PDF_DESC=	Build and install rem2pdf (requires Perl)

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

.include <bsd.port.options.mk>

pre-configure:
	${REINPLACE_CMD} \
	    -e 's#DEFAULT_LATITUDE 39#DEFAULT_LATITUDE ${DEFAULT_LATITUDE}#' \
	    -e 's#DEFAULT_LONGITUDE 39#DEFAULT_LONGITUDE ${DEFAULT_LONGITUDE}#' \
	    -e 's#Ottawa#${LOCATION}#' ${WRKSRC}/src/custom.h

pre-configure-A4-on:
	${REINPLACE_CMD} -e 's#"Letter", 612, 792#"A4", 595, 842#' ${WRKSRC}/src/custom.h

pre-configure-TCLTK-on:
	${REINPLACE_CMD} -e '/^exec/s,wish,${WISH},' ${WRKSRC}/scripts/tkremind.in

do-install-REM2HTML-on:
	cd ${WRKSRC}/rem2html && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install

do-install-REM2PDF-on:
	cd ${WRKSRC}/rem2pdf && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} Makefile.top ${MAKE_ARGS} all
	cd ${WRKSRC}/rem2pdf && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} Makefile.top ${MAKE_ARGS} install

post-install-TCLTK-off:
	${RM} ${STAGEDIR}${PREFIX}/bin/tkremind
	${RM} ${STAGEDIR}${PREFIX}/man/man1/tkremind.1

.include <bsd.port.mk>
