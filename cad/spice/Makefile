# New ports collection makefile for:    spice
# Version required:     3f5
# Date created:         26 Mar 96
# Whom:                 Julian Jenkins <kaveman@magna.com.au>
#
# $Id: Makefile,v 1.11 1998/09/27 08:16:26 steve Exp $
#

DISTNAME=	sp3f4.kit
PKGNAME=	spice-3f5
CATEGORIES=	cad
MASTER_SITES=	ftp://ic.eecs.berkeley.edu/pub/Spice3/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	kaveman@magna.com.au

BROKEN_ELF=	install

# documentation in ftp://ic.eecs.berkeley.edu/pub/Spice3/um.3f3.ps

#		These are included as patch-ab
#PATCH_SITES=	ftp://ilpsoft.eecs.berkeley.edu/pub/SPICE3F5/
#PATCHFILES=	grid.patch newcoms.patch spsmp.patch

USE_XLIB=	yes
NO_WRKSUBDIR=	yes
MAN1=		sconvert.1 nutmeg.1 spice.1
MAN3=		mfb.3
MAN5=		mfbcap.5

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/spice3
	${INSTALL_DATA} ${WRKSRC}/examples/*.cir ${PREFIX}/share/examples/spice3
.endif

.include <bsd.port.mk>
