# New ports collection makefile for:    spice
# Version required:     3f4 (3f5?)
# Date created:         26 Mar 96
# Whom:                 Julian Jenkins <kaveman@magna.com.au>
#
#

DISTNAME=       spice3f4
PKGNAME=	spice-3f4
CATEGORIES+=	cad
MASTER_SITES=	ftp://sunsite.unc.edu/pub/Linux/apps/circuits/

#PATCH_SITES=	ftp://ic.eecs.berkeley.edu/pub/Spice3/3f4patches
#PATCHFILES=	grid.patch newcoms.patch spsmp.patch
# documentation in ftp://ic.eecs.berkeley.edu/pub/Spice3/um.3f3.ps

MAINTAINER=	kaveman@magna.com.au

RESTRICTED=	"export restrictions"

post-install:
	chmod a+rx ${PREFIX}/bin/spice3 ${PREFIX}/bin/nutmeg \
	    ${PREFIX}/bin/sconvert ${PREFIX}/bin/help ${PREFIX}/bin/proc2mod \
	    ${PREFIX}/bin/multidec
	strip ${PREFIX}/bin/spice3 ${PREFIX}/bin/nutmeg \
	    ${PREFIX}/bin/sconvert ${PREFIX}/bin/help ${PREFIX}/bin/proc2mod \
	    ${PREFIX}/bin/multidec
	chmod -R a+rX ${PREFIX}/share/spice
	chmod a+rx ${PREFIX}/man/man5/mfbcap.5.gz \
	    ${PREFIX}/man/man1/sconvert.1.gz ${PREFIX}/man/man1/nutmeg.1.gz \
	    ${PREFIX}/man/man1/spice.1.gz ${PREFIX}/man/man3/mfb.3.gz

.include <bsd.port.mk>
