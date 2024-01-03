PORTNAME=	quirc
PORTVERSION=	0.9.84
PORTREVISION=	6
CATEGORIES=	irc tk
MASTER_SITES=	https://BSDforge.com/projects/source/irc/quirc/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Tcl/Tk IRC client for the X Window System
WWW=		https://BSDforge.com/projects/irc/quirc/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		Unfetchable

USES=		tk xorg
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wish=${WISH} \
		--with-tcl-include-dir=${TCL_INCLUDEDIR} \
		--with-tk-include-dir=${TK_INCLUDEDIR} \
		--with-tcl-lib-dir=${TCL_LIBDIR} \
		--with-tk-lib-dir=${TK_LIBDIR} \
		--with-tcl-lib=tcl${TCL_SHLIB_VER} \
		--with-tk-lib=tk${TCL_SHLIB_VER} \
		--with-tcl-version=${TCL_VER}
USE_XORG=	ice sm x11

PORTDOCS=	AUTHORS ChangeLog FAQ NEWS README doc/*.txt

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/common
	${LN} -sf ../install.tcl ${STAGEDIR}${DATADIR}/common
	@${MKDIR} ${STAGEDIR}${DATADIR}/themes
	${LN} -sf ../default.tcl ${STAGEDIR}${DATADIR}/themes

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
