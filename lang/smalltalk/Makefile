# New ports collection makefile for:	smalltalk
# Version required:	1.1.1
# Date created:		09 Feb 1995
# Whom:			gpalmer
#
# $Id: Makefile,v 1.14 1997/11/29 14:15:01 jraynard Exp $
#

DISTNAME=	smalltalk-1.1.5
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	smalltalk

MAINTAINER=	jraynard@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-optimize --with-readline

IS_INTERACTIVE=	yes
NO_PACKAGE=	"Installation requires interaction"

# For some reason configure doesn't set this up properly and my feeble
# brain can't see how to fix it.
CFLAGS+=	-I${X11BASE}/include

do-install:
	@echo "Installing method definitions..."
	@ if [ ! -d ${PREFIX}/lib/smalltalk ]; then ${MKDIR} ${PREFIX}/lib/smalltalk; fi
	@(cd ${WRKSRC}; ${CP} *.st ${PREFIX}/lib/smalltalk)
	@(cd ${PREFIX}/lib/smalltalk ; chmod +r *.st)
	@echo
	@echo "To complete the installation of GNU Smalltalk, do"
	@echo "	cd ${WRKSRC};"
	@echo "./gst -iV"
	@echo "to test the interpreter and create the image."
	@echo
	@echo "When you are satisfied everything works, do Control-D to quit"
	@echo "followed by"
	@echo "cp gst ${PREFIX}/bin"
	@echo "cp gst.im ${PREFIX}/lib/smalltalk"
	@echo "to install the interpreter and image."
	@echo
	@echo "If Emacs is installed, you may also wish to copy the"
	@echo "*st.el files to the Emacs Lisp directory. This will enable you"
	@echo "to configure Emacs for Interactor mode."
	@echo
	@echo ">>Please read the file"
	@echo "${WRKSRC}/info/gst.txi"
	@echo "for more information.<<"
	@echo

.include <bsd.port.mk>
