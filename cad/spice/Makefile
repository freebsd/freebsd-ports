# New ports collection makefile for:    spice
# Version required:     3f4 (3f5?)
# Date created:         26 Mar 96
# Whom:                 Julian Jenkins <kaveman@magna.com.au>
#
# $Id: Makefile,v 1.7 1996/12/24 07:31:49 asami Exp $
#

DISTNAME=       sp3f4.kit
PKGNAME=	spice-3f4
CATEGORIES=	cad
MASTER_SITES=	ftp://ic.eecs.berkeley.edu/pub/Spice3/
EXTRACT_SUFX=   .tar.Z

#PATCH_SITES=	ftp://ic.eecs.berkeley.edu/pub/Spice3/3f4patches
#PATCHFILES=	grid.patch newcoms.patch spsmp.patch
# documentation in ftp://ic.eecs.berkeley.edu/pub/Spice3/um.3f3.ps

MAINTAINER=	kaveman@magna.com.au

NO_WRKSUBDIR=	yes
MAN1=		sconvert.1 nutmeg.1 spice.1
MAN3=		mfb.3
MAN5=		mfbcap.5

post-install:
	chmod a+rx ${PREFIX}/bin/spice3 ${PREFIX}/bin/nutmeg \
	    ${PREFIX}/bin/sconvert ${PREFIX}/bin/help ${PREFIX}/bin/proc2mod \
	    ${PREFIX}/bin/multidec
	strip ${PREFIX}/bin/spice3 ${PREFIX}/bin/nutmeg \
	    ${PREFIX}/bin/sconvert ${PREFIX}/bin/help ${PREFIX}/bin/proc2mod \
	    ${PREFIX}/bin/multidec
	chmod -R a+rX ${PREFIX}/share/spice

.include <bsd.port.mk>
