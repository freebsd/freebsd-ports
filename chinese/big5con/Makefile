# New ports collection makefile for:	big5con
# Version required:	0.92b
# Date created:		07 Jan 1997
# Whom:			Hung-Chi Chu <hcchu@r350.ee.ntu.edu.tw>
#
# $Id: Makefile,v 1.6 1998/09/27 00:00:24 steve Exp $
#

DISTNAME=	big5con-0.92b
PKGNAME=	zh-big5con-0.92b
CATEGORIES=	chinese
MASTER_SITES=	ftp://freebsd.ntu.edu.tw/freebsd/woju/source/ \
		ftp://freebsd.ntu.edu.tw/freebsd/woju/binary/ \
		ftp://ftp.hinet.net/OS/FreeBSD/taiwan/NTU/woju/source/ \
		ftp://ftp.hinet.net/OS/FreeBSD/taiwan/NTU/woju/binary/ \
		ftp://freebsd.csie.nctu.edu.tw/pub/taiwan/NTU/woju/source/ \
		ftp://freebsd.csie.nctu.edu.tw/pub/taiwan/NTU/woju/binary/
DISTFILES=	big5con-0.92b.tgz b5cbin.tgz

MAINTAINER=	woju@freebsd.ee.ntu.edu.tw

#from Hung-Chi Chu <hcchu@r350.ee.ntu.edu.tw>:  The font is transformed from
#	a font with restrictive copyright, so I think you can't distribute
#	it on the CDROM.
RESTRICTED=	"The font 'taipei16.bdf' has restrictive copyrighted"

pre-install:
	@if [ ! -f ${PREFIX}/lib/fonts/taipei16.bdf.gz ]; then \
		tar xvfzp ${DISTDIR}/b5cbin.tgz -C ${PREFIX}; \
	fi

post-install:
	@echo
	@echo "---------------------------------------------------------------"
	@echo "You need to add a line 'options SYSVSHM' to your kernel config."
	@echo "Use 'b5c' to run the big5 console."
	@echo "---------------------------------------------------------------"
	@echo

.include <bsd.port.mk>
