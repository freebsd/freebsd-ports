# New ports collection makefile for:	wu-ftpd
# Version required:     2.5.*
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#
# REMINDER: to use ftpaccess(5) you need to specify -a in command line,
# it is changed from previous versions

DISTNAME=       wu-ftpd-2.5.0
CATEGORIES=	ftp
MASTER_SITES=   ftp://ftp.vr.net/pub/wu-ftpd/wu-ftpd/

PATCH_SITES=	ftp://ftp.wu-ftpd.org/pub/wu-ftpd/quickfixes/apply_to_2.5.0/
PATCHFILES=     \
		data-limit.patch \
		deny.not.nameserved.patch \
		mapped.path.overrun.patch \
		not.in.class.patch \
		rfc931.timeout.patch

MAINTAINER=     ache@FreeBSD.org

Y2K=		http://www.cetis.hvu.nl/~koos/wu-ftpd-faq.html#QA35

MAN1=		ftpcount.1 ftpwho.1
MAN5=		ftpaccess.5 ftphosts.5 ftpconversions.5 xferlog.5
MAN8=		ftpd.8 ftpshut.8

do-build:
	cd ${WRKSRC} && ./build fbs

.include <bsd.port.mk>
