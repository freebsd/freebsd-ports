# New ports collection makefile for:	wu-ftpd
# Version required:     2.4.2-vr
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.23 1999/03/09 12:07:09 ache Exp $
#
# REMINDER: to use ftpaccess(5) you need to specify -a in command line,
# it is changed from previous versions

DISTNAME=       wu-ftpd-2.4.2-vr17
PKGNAME=        wu-ftpd-2.4.2v17
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.vr.net/pub/wu-ftpd/

MAINTAINER=     ache@FreeBSD.org

Y2K=		http://www.cetis.hvu.nl/~koos/wu-ftpd-faq.html#QA31

MAN1=		ftpcount.1 ftpwho.1
MAN5=		ftpaccess.5 ftphosts.5 ftpconversions.5 xferlog.5
MAN8=		ftpd.8 ftpshut.8

do-build:
	cd ${WRKSRC} && ./build fbs

.include <bsd.port.mk>
