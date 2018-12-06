# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libredwg
PORTVERSION=	0.7
CATEGORIES=	cad devel
MASTER_SITES=	GNU

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Library and command line tools to handle DWG files

LICENSE=	GPLv3+

USES=		libtool tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INFO=		LibreDWG
PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	DOCS PSLIB
OPTIONS_DEFAULT=	PSLIB
PSLIB_DESC=	PostScript export support (dwg2ps)

PSLIB_LIB_DEPENDS=	libps.so:print/pslib
# XXX: shall `localbase' be put on global USES, it would require explicit
# PSLIB_CONFIGURE_ENV_OFF=	ac_cv_lib_ps_PS_open_file=no
PSLIB_USES=		localbase
PSLIB_PLIST_FILES=	bin/dwg2ps

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
