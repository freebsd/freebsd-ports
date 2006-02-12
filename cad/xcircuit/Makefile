# New ports collection makefile for:	xcircuit
# Date created:		3 Apr 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	xcircuit
PORTVERSION=	3.4.11
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	http://opencircuitdesign.com/xcircuit/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 drawing program [especially for circuit schematics]

BROKEN=		Size mismatch

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_TCL=	84
USE_TK=		84
USE_GHOSTSCRIPT_RUN=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR}

CFLAGS+=	-fPIC

MAN1=		xcircuit.1

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test/s| == | = |g ; \
		 s|-Wl,-Bshareable,-x|-shared -Wl,-x|g ; \
		 s|TCL_LIB_NAME=.*$$|TCL_LIB_NAME="tcl${TCL_VER:S/.//}"|g ; \
		 s|TK_LIB_NAME=.*$$|TK_LIB_NAME="tk${TK_VER:S/.//}"|g ; \
		 s|wish |${WISH:T} |g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC}/examples --exclude "*.py" -cf - . | \
		${TAR} -C ${EXAMPLESDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
