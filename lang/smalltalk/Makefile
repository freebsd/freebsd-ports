# New ports collection makefile for:	smalltalk
# Version required:	1.1.1
# Date created:		09 Feb 1995
# Whom:			gpalmer
#
# $FreeBSD$
#

DISTNAME=	smalltalk-1.1.5
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	smalltalk

MAINTAINER=	jraynard@FreeBSD.org

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-optimize --with-readline

IS_INTERACTIVE=	yes
NO_PACKAGE=	"Installation requires interaction"

# For some reason configure doesn't set this up properly and my feeble
# brain can't see how to fix it.
CFLAGS+=	-I${X11BASE}/include

do-install:
	@${ECHO_MSG} "Installing method definitions..."
	@ if [ ! -d ${PREFIX}/lib/smalltalk ]; then ${MKDIR} ${PREFIX}/lib/smalltalk; fi
	@(cd ${WRKSRC}; ${CP} *.st ${PREFIX}/lib/smalltalk)
	@(cd ${PREFIX}/lib/smalltalk ; ${CHMOD} +r *.st)
	@${ECHO_MSG}
	@${ECHO_MSG} "To complete the installation of GNU Smalltalk, do"
	@${ECHO_MSG} "	cd ${WRKSRC};"
	@${ECHO_MSG} "./gst -iV"
	@${ECHO_MSG} "to test the interpreter and create the image."
	@${ECHO_MSG}
	@${ECHO_MSG} "When you are satisfied everything works, do Control-D to quit"
	@${ECHO_MSG} "followed by"
	@${ECHO_MSG} "cp gst ${PREFIX}/bin"
	@${ECHO_MSG} "cp gst.im ${PREFIX}/lib/smalltalk"
	@${ECHO_MSG} "to install the interpreter and image."
	@${ECHO_MSG}
	@${ECHO_MSG} "If Emacs is installed, you may also wish to copy the"
	@${ECHO_MSG} "*st.el files to the Emacs Lisp directory. This will enable you"
	@${ECHO_MSG} "to configure Emacs for Interactor mode."
	@${ECHO_MSG}
	@${ECHO_MSG} ">>Please read the file"
	@${ECHO_MSG} "${WRKSRC}/info/gst.txi"
	@${ECHO_MSG} "for more information.<<"
	@${ECHO_MSG}

.include <bsd.port.mk>
