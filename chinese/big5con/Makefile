# New ports collection makefile for:	big5con
# Version required:	0.1
# Date created:		07 Jan 1997
# Whom:			Hung-Chi Chu <hcchu@r350.ee.ntu.edu.tw>
#
# $Id: Makefile,v 1.2 1997/02/17 20:33:32 obrien Exp $
#
# This port is adapted from japanese/kon
#

DISTNAME=	kon
PKGNAME=	cn-big5con-0.1
CATEGORIES=	chinese
# note kon is only in first directory and
# fonts are only in the other two directories
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/linux-j/JE-sources/JE/ \
		ftp://nctuccca.edu.tw/Chinese/ifcss/software/fonts/misc/bdf/ \
		ftp://nctuccca.edu.tw/Chinese/ifcss/software/fonts/big5/bdf/
DISTFILES=	kon-0.99.4e.tgz 8x16.bdf.gz taipei16.bdf.gz

MAINTAINER=	hcchu@r350.ee.ntu.edu.tw

#from Hung-Chi Chu <hcchu@r350.ee.ntu.edu.tw>:  The font is transformed from
#	a font with restrictive copyright, so I think you can't distribute
#	it on the CDROM.
RESTRICTED=	"The font 'taipei16.bdf' has restrictive copyrighted"
EXTRACT_ONLY=	kon-0.99.4e.tgz
USE_GMAKE=	yes

post-configure:
	${SED} -e 's%%CURDIR%%${.CURDIR}' \
	  -e 's%%PREFIX%%${PREFIX}' \
	  -e 's%%DISTDIR%%${DISTDIR}' \
	  ${FILESDIR}/dotconfig > ${WRKSRC}/.config

post-install:
	@echo
	@echo "---------------------------------------------------------------"
	@echo "You need to add a line 'options SYSVSHM' to your kernel config."
	@echo "Use 'big5con' to run the big5 console."
	@echo "---------------------------------------------------------------"
	@echo

.include <bsd.port.mk>
