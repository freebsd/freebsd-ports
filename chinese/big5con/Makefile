# New ports collection makefile for:	big5con
# Version required:	0.92b
# Date created:		07 Jan 1997
# Whom:			Hung-Chi Chu <hcchu@r350.ee.ntu.edu.tw>
#
# $Id: Makefile,v 1.9 1999/01/06 05:00:25 simokawa Exp $
#

DISTNAME=	big5con-0.92e
PKGNAME=	zh-big5con-0.92e
CATEGORIES=	chinese
MASTER_SITES=	ftp://freebsd.ntu.edu.tw/freebsd/woju/source/ \
		ftp://freebsd.ntu.edu.tw/freebsd/woju/binary/ \
		ftp://bsd.sinica.edu.tw/pub/FreeBSD/taiwan/users/woju/source/ \
		ftp://bsd.sinica.edu.tw/pub/FreeBSD/taiwan/users/woju/binary/ \
		ftp://freebsd.csie.nctu.edu.tw/pub/taiwan/NTU/woju/source/ \
		ftp://freebsd.csie.nctu.edu.tw/pub/taiwan/NTU/woju/binary/
DISTFILES=	big5con-0.92e.tgz b5cbin-pa.tgz

MAINTAINER=	woju@freebsd.ee.ntu.edu.tw

ONLY_FOR_ARCHS=	i386

EXTRACT_ONLY=	${DISTNAME}.tgz

# With the help from pa@freebsd.ee.ntu.edu.tw
# +0.92d use kc-fonts, whcih can be included in cdrom, instead of taipei-fonts.
# Note: 0.92c is restricted due to the taipei-fonts-copyright.
# 
# 1999/02/12: 0.92d -> 0.92e
# Fix some bugs
# ftp://bsd.sinica.edu.tw/pub/FreeBSD/taiwan/users/woju/source/b5c-d2e.patch

pre-install:
	@if [ ! -f ${PREFIX}/lib/fonts/kc16.smf ]; then \
		tar xvfzp ${DISTDIR}/b5cbin-pa.tgz -C ${PREFIX}; \
	fi

post-install:
	@echo
	@echo "---------------------------------------------------------------"
	@echo "You need to add a line 'options SYSVSHM' to your kernel config."
	@echo "Use 'b5c' to run the big5 console."
	@echo "---------------------------------------------------------------"
	@echo

.include <bsd.port.mk>
