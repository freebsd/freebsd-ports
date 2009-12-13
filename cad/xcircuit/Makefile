# New ports collection makefile for:	xcircuit
# Date created:		3 Apr 1998
# Whom:			Pedro F. Giffuni
#
# $FreeBSD$
#

PORTNAME=	xcircuit
PORTVERSION=	3.6.164
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	http://opencircuitdesign.com/xcircuit/archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 drawing program [especially for circuit schematics]

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

CFLAGS+=	-fPIC

MAN1=		xcircuit.1

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/test/s| == | = |g ; \
		 s|-Wl,-Bshareable,-x|-shared -Wl,-x|g ; \
		 s|TCL_LIB_NAME=.*$$|TCL_LIB_NAME="tcl${TCL_VER:S/.//}"|g ; \
		 s|TK_LIB_NAME=.*$$|TK_LIB_NAME="tk${TK_VER:S/.//}"|g ; \
		 s|wish |${WISH:T} |g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/.xcircuitrc ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.lgf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.lps ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.ps ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.sim ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
