# New ports collection makefile for:	kappafont
# Version required:	0.3
# Date created:		12 Nov 1998
# Whom: Kawaguti Ginga <ginga@athena.club.or.jp>
#
# $Id: Makefile,v 1.4 1998/08/07 22:43:07 asami Exp $
#

DISTNAME=	Kappa20-0.3
PKGNAME=	ja-kappa20-0.3
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	ftp://ftp.jaist.ac.jp/pub/misc/character/fonts/kappa/

MAINTAINER=	ginga@athena.club.or.jp

ALL_TARGET=	default
USE_X_PREFIX=	yes
MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}"
PLIST_SUB=	PERL=${PERL}

pre-install:
	@if [ ! -d ${PREFIX}/lib/X11/fonts/local ]; then \
	    ${ECHO} '**********************************************************************'; \
	    ${ECHO} "****** ${PREFIX}/lib/X11/fonts/local/ doesn't exist."; \
	    ${ECHO} "****** Creating ${PREFIX}/lib/X11/fonts/local/"; \
	    ${MKDIR} ${PREFIX}/lib/X11/fonts/local/; \
	    ${ECHO} '****** Please upgrade your XFree86 to 3.3.3 or upper,'; \
	    ${ECHO} "****** or add this directory to your /etc/XF86Config's FontPath entry."; \
	    ${ECHO} '**********************************************************************'; \
	fi

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/kappa20
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${PREFIX}/share/doc/kappa20/
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/pcf/fonts.alias.kappa ${PREFIX}/share/doc/kappa20/
.endif

.include <bsd.port.mk>
