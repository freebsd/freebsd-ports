# New ports collection makefile for:	wu-ftpd
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#
# REMINDER: to use ftpaccess(5) you need to specify -a in command line,
# it is changed from previous versions

PORTNAME=	wu-ftpd
PORTVERSION=	2.6.1
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.wu-ftpd.org/pub/wu-ftpd/

MAINTAINER=	ache@FreeBSD.org

MAN1=		ftpcount.1 ftpwho.1
MAN5=		ftpaccess.5 ftphosts.5 ftpconversions.5 xferlog.5
MAN8=		ftpd.8 ftpshut.8 ftprestart.8 privatepw.8

pre-patch:
	@${CP} ${WRKSRC}/config.h.noac ${WRKSRC}/config.h
	@${CP} ${WRKSRC}/src/pathnames.h.noac ${WRKSRC}/src/pathnames.h

do-build:
	cd ${WRKSRC} && ./build fbs

.include <bsd.port.mk>
