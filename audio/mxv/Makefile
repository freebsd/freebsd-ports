# New ports collection makefile for:	mxv
# Version required:	1.10
# Date created:		17 March 1997
# Whom:			davidn@blaze.net.au
#
# $Id$
#

DISTNAME=	mxv-v1.10-source
PKGNAME=	mxv-1.10
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.ccmrc.ucsb.edu/pub/MixViews/source/

#PATCH_SITES=	ftp://ftp.ccmrc.ucsb.edu/pub/MixViews/source/
#PATCHFILES=	mxv-v1.10-patch01
#Unfortunately, the above vendor patch does not apply cleanly,
#and and a hand-edited version is supplied in the patches subdir

MAINTAINER=	davidn@blaze.net.au
#From InterViews 3.1
BUILD_DEPENDS=	ivmkmf

USE_IMAKE=	yes
WRKSRC=		$(WRKDIR)
#ivmkmf -a (with makedepend) not recommended by documentation
XMKMF=		env CPU=FREEBSD ivmkmf;make Makefiles

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/FREEBSD/mxv ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/MiXViews.res ${PREFIX}/lib/X11/app-defaults/MiXViews

.include <bsd.port.mk>
