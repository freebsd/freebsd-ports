# Created by: Pedro F. Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	xcircuit
PORTVERSION=	3.7.45
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	http://opencircuitdesign.com/xcircuit/archive/ \
		http://fossies.org/unix/misc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 drawing program [especially for circuit schematics]

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

OPTIONS_DEFINE=	EXAMPLES

USE_XORG=	xpm xt
USE_TCL=	85
USE_TCL_BUILD=	85
USE_TK=		85
USE_TK_BUILD=	85
USE_GHOSTSCRIPT_RUN=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR}
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"
MAKE_JOBS_SAFE=	yes

MAN1=		xcircuit.1

DESKTOP_ENTRIES="Xcircuit" "${COMMENT}" "${DATADIR}/pixmaps/xcircuit.gif" \
		"${PORTNAME}" "" "false"

# Restrict to stable (odd) versions, indicated by the second component.
PORTSCOUT=	limitw:1,odd

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/test/s| == | = |g ; \
		 s|TCL_LIB_NAME=.*$$|TCL_LIB_NAME="tcl${TCL_VER:S/.//}"|g ; \
		 s|TK_LIB_NAME=.*$$|TK_LIB_NAME="tk${TK_VER:S/.//}"|g ; \
		 s|wish |${WISH:T} |g ; \
		 s|-fpic|-fPIC|g' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/.xcircuitrc ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.lgf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.lps ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.ps ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.sim ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
