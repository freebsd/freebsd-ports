# New ports collection makefile for:	xcircuit
# Date created:		3 Apr 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	xcircuit
PORTVERSION=	3.4.22
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	http://opencircuitdesign.com/xcircuit/archive/ \
		http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	An X11 drawing program [especially for circuit schematics]

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_TCL=	84
USE_TCL_BUILD=	84
USE_TK=		84
USE_TK_BUILD=	84
USE_GHOSTSCRIPT_RUN=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR}

CFLAGS+=	-fPIC

MAN1=		xcircuit.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/test/s| == | = |g ; \
		 s|-Wl,-Bshareable,-x|-shared -Wl,-x|g ; \
		 s|TCL_LIB_NAME=.*$$|TCL_LIB_NAME="tcl${TCL_VER:S/.//}"|g ; \
		 s|TK_LIB_NAME=.*$$|TK_LIB_NAME="tk${TK_VER:S/.//}"|g ; \
		 s|wish |${WISH:T} |g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/.xcircuitrc ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.lgf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.lps ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.ps ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.sim ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
