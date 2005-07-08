# New ports collection makefile for:	xcircuit
# Date created:		3 Apr 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	xcircuit
PORTVERSION=	3.3.19
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	http://xcircuit.ece.jhu.edu/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 drawing program [especially for circuit schematics]

LIB_DEPENDS=	tk84:${PORTSDIR}/x11-toolkits/tk84

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GHOSTSCRIPT_RUN=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib/tcl8.4 \
		--with-tk=${LOCALBASE}/lib/tk8.4

CFLAGS+=	-fPIC -I${X11BASE}/include

WISH=		${LOCALBASE}/bin/wish8.4

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test/s| == | = |g ; \
		 s|TCL_LIB_NAME=.*$$|TCL_LIB_NAME="tcl84"|g ; \
		 s|TK_LIB_NAME=.*$$|TK_LIB_NAME="tk84"|g ; \
		 s|-Wl,--version-script=|--version-script |g' ${WRKSRC}/configure
.for file in lib/tcl/xcircuit.sh.m4 lib/tcl/tkcon.tcl
	@${REINPLACE_CMD} -e 's|exec wish|exec ${WISH}|g' ${WRKSRC}/${file}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC}/examples --exclude "*.py" -cf - . | \
		${TAR} -C ${EXAMPLESDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
