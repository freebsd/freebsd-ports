# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quirc
PORTVERSION=	0.9.84
PORTREVISION=	5
CATEGORIES=	irc tk
MASTER_SITES=	LOCAL:local # This ends up being empty.

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl/Tk IRC client for the X Window System

OPTIONS_DEFINE=	DOCS

BROKEN=		Unfetchable
USES=		tk
USE_XORG=	xt

GNU_CONFIGURE=	yes
MAKE_ENV+=	DESTDIR=${STAGEDIR}

MYPORTDOCS=	AUTHORS ChangeLog FAQ NEWS README doc/color.txt \
		doc/dccresum.txt doc/links.txt doc/nickcomp.txt \
		doc/quedit.txt doc/rfc1459.txt doc/tdcc.txt
PORTDOCS=	*


.include <bsd.port.options.mk>

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
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
