# New ports collection makefile for:	jpeg
# Version required:     6
# Date created:		6 November 1994
# Whom:			smace
#
# $Id: Makefile,v 1.10 1995/10/11 08:21:33 asami Exp $
#

DISTNAME=       jpegsrc.v6
PKGNAME=        jpeg-6
CATEGORIES+=	graphics
MASTER_SITES=	ftp://nic.switch.ch/mirror/ghost/ \
		ftp://ftp.zam.kfa-juelich.de/pub/graphics/JPEG/ \
		ftp://scotch.csua.berkeley.edu/pub/gimp/old/ \
		ftp://ftp.efd.lth.se/pub/graphic/ \
		ftp://rcs1.urz.tu-dresden.de/pub/soft/tex/tex.dante/support/ghostscript/ \
		ftp://sun.dante.de/tex-archive/support/ghostscript/

WRKSRC=         ${WRKDIR}/jpeg-6
GNU_CONFIGURE=	yes
INSTALL_TARGET= install install-lib

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
