# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libredwg
PORTVERSION=	0.9
CATEGORIES=	cad devel
MASTER_SITES=	GNU

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Library and command line tools to handle DWG files

LICENSE=	GPLv3+

USES=		libtool tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-trace
USE_LDCONFIG=	yes
TEST_TARGET=	check

INFO=		LibreDWG
PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	DOCS PSLIB PYTHON
OPTIONS_DEFAULT=	PSLIB
PSLIB_DESC=	PostScript export support (dwg2ps)

PSLIB_LIB_DEPENDS=	libps.so:print/pslib
# XXX: shall `localbase' be put on global USES, it would require explicit
# PSLIB_CONFIGURE_ENV_OFF=	ac_cv_lib_ps_PS_open_file=no
PSLIB_USES=		localbase
PSLIB_PLIST_FILES=	bin/dwg2ps

PYTHON_CONFIGURE_OFF=	--disable-python

post-patch:
# XXX: switch the order of #include's to unbreak on powerpc/sparc64
# which are still based on gcc-4.2.1 (should be no-op elsewhere)
	@${REINPLACE_CMD} -e '/#include "com/ { x; s/^/#include <stdlib.h>/; \
		G; }; 24d' ${WRKSRC}/src/common.c

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
