# New ports collection makefile for:	smalltalk
# Version required:	1.1.1
# Date created:		09 Feb 1995
# Whom:			gpalmer
#
# $Id: Makefile,v 1.10 1996/11/12 02:19:10 obrien Exp $
#

DISTNAME=	smalltalk-1.1.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	jraynard@FreeBSD.ORG

IS_INTERACTIVE=	yes
NO_PACKAGE=yes

pre-configure:
	@{CP} ${FILESDIR}/m-fbsd-2.h ${WRKSRC}/config/m-fbsd-2.h
	@(cd ${WRKSRC} ; ./config.mst fbsd-2)
	@${TOUCH} ${TOUCH_FLAGS} ${CONFIGURE_COOKIE}

do-build:
	if [ -d ${X11BASE} ]; then (cd ${WRKSRC}/stix; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET}; ${CP} mst *.st ${WRKSRC}); else (cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET}); fi;

do-install:
	@echo "Installing method definitions..."
	@ if [ ! -d ${PREFIX}/lib/smalltalk ]; then ${MKDIR} ${PREFIX}/lib/smalltalk; fi
	@(cd ${WRKSRC}; ${CP} *.st ${PREFIX}/lib/smalltalk)
	@(cd ${PREFIX}/lib/smalltalk ; chmod +r *.st)
	@echo
	@echo
	@echo "To complete the installation of GNU Smalltalk, do"
	@echo "	cd ${WRKSRC}; ./mst -iV"
	@echo "to build the image and test the interpreter."
	@echo
	@echo "When you are satisfied everything works, do Control-D to quit"
	@echo "(this will give a parse error, which can be safely ignored)"
	@echo "followed by 'cp mst ${PREFIX}/bin'."
	@echo
	@echo "Finally, if Emacs is installed, you may also wish to copy the"
	@echo "st*.el files to the Emacs Lisp directory. This will enable you"
	@echo "to configure Emacs for Interactor mode."
	@echo
	@echo ">>Please read the file" 
	@echo "${WRKSRC}/mst.texinfo"
	@echo "for more information.<<"
	@echo

.include <bsd.port.mk>
