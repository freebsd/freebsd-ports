# New ports collection makefile for:	wu-ftpd
# Version required:     2.4.2-beta
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.18 1998/07/22 10:14:12 ache Exp $
#
# REMINDER: to use ftpaccess(5) you need to specify -a in command line,
# it is changed from previous versions

DISTNAME=       wu-ftpd-2.4.2-beta-18
PKGNAME=        wu-ftpd-2.4.2b18
CATEGORIES=	net
# AUSCERT recommendation
MASTER_SITES=   ftp://ftp.academ.com/pub/wu-ftpd/private/
EXTRACT_SUFX=   .tar.Z

do-build:
	cd ${WRKSRC} && ./build fbs

MAINTAINER=     ache@FreeBSD.org

Y2K=		http://www.cetis.hvu.nl/~koos/wu-ftpd-faq.html#QA31

MAN1=		ftpcount.1 ftpwho.1
MAN5=		ftpaccess.5 ftphosts.5 ftpconversions.5 xferlog.5
MAN8=		ftpd.8 ftpshut.8

.include <bsd.port.mk>
