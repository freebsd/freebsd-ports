# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libredwg
PORTVERSION=	0.12.3
CATEGORIES=	cad devel
MASTER_SITES=	GNU

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Library and command line tools to handle DWG files

LICENSE=	GPLv3+

USES=		libtool tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-trace --with-perl-install=no
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

INFO=		LibreDWG
PORTDOCS=	AUTHORS ChangeLog NEWS README TODO
PORTEXAMPLES=	dwgadd.example

OPTIONS_DEFINE=	DOCS EXAMPLES PCRE PSLIB PYTHON
OPTIONS_DEFAULT=	PCRE PSLIB
OPTIONS_SUB=	yes
PCRE_DESC=	Regular expressions support in dwggrep
PSLIB_DESC=	PostScript export support (dwg2ps)

PCRE_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
PCRE_USES=		localbase
PCRE_CONFIGURE_ENV_OFF=	ac_cv_lib_pcre2_8_pcre2_config_8=no

PSLIB_LIB_DEPENDS=	libps.so:print/pslib
PSLIB_USES=		localbase
PSLIB_CONFIGURE_ENV_OFF=	ac_cv_lib_ps_PS_open_file=no

PYTHON_BUILD_DEPENDS=	swig:devel/swig
PYTHON_USES=		gettext-runtime python:3.6+ shebangfix
PYTHON_CONFIGURE_OFF=	--disable-python
PYTHON_PORTEXAMPLES=	load_dwg.py
PYTHON_VARS=		SHEBANG_FILES+=examples/load_dwg.py

post-patch:
# XXX: switch the order of #include's to unbreak on powerpc/sparc64
# which are still based on gcc-4.2.1 (should be no-op elsewhere)
	@${REINPLACE_CMD} -e '/#include "com/ { x; s/^/#include <stdlib.h>/; \
		G; }; 24d' ${WRKSRC}/src/common.c

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-PYTHON-on:
	${CHMOD} +x ${STAGEDIR}${PREFIX}/share/load_dwg.py

post-install-PYTHON-off:
	${RM} ${STAGEDIR}${PREFIX}/share/load_dwg.py

post-stage:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MV} ${PORTEXAMPLES:S|^|${STAGEDIR}${PREFIX}/share/|} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
