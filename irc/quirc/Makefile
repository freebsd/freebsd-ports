# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quirc
PORTVERSION=	0.9.84
PORTREVISION=	6
CATEGORIES=	irc tk
MASTER_SITES=	https://BSDforge.com/projects/source/irc/quirc/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Tcl/Tk IRC client for the X Window System

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS

USES=		tk xorg
USE_XORG=	xt

GNU_CONFIGURE=	yes
MAKE_ENV+=	DESTDIR=${STAGEDIR}

PORTDOCS=	AUTHORS ChangeLog FAQ NEWS README doc/*.txt

CONFIGURE_ARGS=	--with-wish=${WISH} \
		--with-tcl-include-dir=${TCL_INCLUDEDIR} \
		--with-tk-include-dir=${TK_INCLUDEDIR} \
		--with-tcl-lib-dir=${TCL_LIBDIR} \
		--with-tk-lib-dir=${TK_LIBDIR} \
		--with-tcl-lib=tcl${TCL_SHLIB_VER} \
		--with-tk-lib=tk${TCL_SHLIB_VER} \
		--with-tcl-version=${TCL_VER}

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/common
	${LN} -sf ../install.tcl ${STAGEDIR}${DATADIR}/common
	@${MKDIR} ${STAGEDIR}${DATADIR}/themes
	${LN} -sf ../default.tcl ${STAGEDIR}${DATADIR}/themes

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
