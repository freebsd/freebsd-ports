# New ports collection makefile for:	xcircuit
# Date created:		3 Apr 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	xcircuit
PORTVERSION=	3.1.18
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	http://xcircuit.ece.jhu.edu/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 drawing program [especially for circuit schematics]

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

USE_GHOSTSCRIPT_RUN=	yes

WISH=		${LOCALBASE}/bin/wish8.4

.if defined(WITH_TCLTK)
PKGNAMESUFFIX=	-tcltk
LIB_DEPENDS+=	tk84:${PORTSDIR}/x11-toolkits/tk84
CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib/tcl8.4 \
		--with-tk=${LOCALBASE}/lib/tk8.4
ALL_TARGET=	tcl
INSTALL_TARGET=	install-tcl
PLIST_SUB+=	PYTHON="@comment " NOPYTHON="" TCLTK="" NOTCLTK="@comment "
CFLAGS+=	-I${LOCALBASE}/include/tcl8.4 -I${LOCALBASE}/include/tk8.4 \
		-I${X11BASE}/include
.else
MAN1+=		xcircuit.1
.if defined(WITH_PYTHON)
PKGNAMESUFFIX=	-python
USE_PYTHON=	yes
CONFIGURE_ARGS+=	--with-python
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
PLIST_SUB+=	PYTHON="" NOPYTHON="@comment " TCLTK="@comment " NOTCLTK=""
.else
PLIST_SUB+=	PYTHON="@comment " NOPYTHON="" TCLTK="@comment " NOTCLTK=""
.endif
.endif

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif
.if !defined(WITH_TCLTK)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_TCLTK for Tcl/Tk support"
	@${ECHO_MSG} "      (prevents python support)"
	@${ECHO_MSG} ""
.endif
.if !defined(WITH_PYTHON)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Or define WITH_PYTHON for Python support"
	@${ECHO_MSG} "      (only available without WITH_TCLTK defined)"
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|TCL_LIB_NAME=.*$$|TCL_LIB_NAME="tcl84"|g ; \
		 s|TK_LIB_NAME=.*$$|TK_LIB_NAME="tk84"|g' ${WRKSRC}/configure
.for file in lib/tcl/xcircuit.sh.m4 lib/tcl/tkcon.tcl
	@${REINPLACE_CMD} -e 's|exec wish|exec ${WISH}|g' ${WRKSRC}/${file}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC}/examples --exclude CVS -cf - . | \
		${TAR} -C ${EXAMPLESDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
