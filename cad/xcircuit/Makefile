# Created by: Pedro F. Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	xcircuit
PORTVERSION=	3.7.56
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	http://opencircuitdesign.com/xcircuit/archive/ \
		http://fossies.org/unix/misc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	X11 circuit schematics drawing program

LICENSE=	GPLv2

OPTIONS_DEFINE=	EXAMPLES

USE_XORG=	xpm xscrnsaver xt
USES=	tk gmake
USE_GHOSTSCRIPT_RUN=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR}
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"

DESKTOP_ENTRIES="Xcircuit" "${COMMENT}" "${DATADIR}/pixmaps/${PORTNAME}.gif" \
		"${PORTNAME}" "" "false"

# Restrict to stable (odd) versions, indicated by the second component.
PORTSCOUT=	limitw:1,odd

post-patch:
	@${REINPLACE_CMD} -e '/test/s| == | = |g ; \
		 s|TCL_LIB_NAME=.*$$|TCL_LIB_NAME="tcl${TCL_VER:S/.//}"|g ; \
		 s|TK_LIB_NAME=.*$$|TK_LIB_NAME="tk${TK_VER:S/.//}"|g ; \
		 s|wish |${WISH:T} |g ; \
		 s|-fpic|-fPIC|g' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/.xcircuitrc ${STAGEDIR}/${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.lgf ${STAGEDIR}/${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.lps ${STAGEDIR}/${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.ps ${STAGEDIR}/${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.sim ${STAGEDIR}/${EXAMPLESDIR}

.include <bsd.port.mk>
