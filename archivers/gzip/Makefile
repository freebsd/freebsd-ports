# New ports collection makefile for:	gzip
# Date created:				27 July 2002
# Whom:					cyrille.lefevre@laposte.net
#
# $FreeBSD$
#

PORTNAME=	gzip
PORTVERSION=	1.3.3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU_ALPHA}
MASTER_SITE_SUBDIR=	${PORTNAME}
# EXTRACT_SUFX=	.tar

MAINTAINER=	cyrille.lefevre@laposte.net

MASTER_SITES=	ftp://ftp.digex.net/pub/linux/slackware/slackware-8.1/source/a/gzip/ \
		ftp://sunfreeware.risq.qc.ca/SOURCES/ \
		ftp://ftp.muug.mb.ca/mirror/slackware/slackware/slackware-8.1/source/a/gzip/ \
		ftp://sunsite.cnlab-switch.ch/mirror/slackware/slackware-8.1/source/a/gzip/ \
		ftp://sunsite.cnlab-switch.ch/mirror/solaris-freeware/SOURCES/ \
		ftp://ftp.informatik.rwth-aachen.de/pub/comp/Linux/slackware/slackware-current/source/a/gzip/ \
		ftp://ftp.sunsite.auc.dk/disk2/slackware/slackware-8.1/source/a/gzip/ \
		ftp://ftp.ist.utl.pt/1/slackware/slackware-8.1/source/a/gzip/ \
		ftp://ftp.carrier.kiev.ua/pub/Linux/slackware/source/a/gzip/ \
		ftp://ftp.is.co.za/linux/distributions/slackware/slackware-8.1/source/a/gzip/ \
		ftp://ftp.monash.edu.au/pub/disk10/slackware/slackware-8.1/source/a/gzip/

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

MAN1=	gunzip.1 gzexe.1 gzip.1 zcat.1 zcmp.1 zdiff.1 zforce.1 \
	zgrep.1 zless.1 zmore.1 znew.1

post-configure:
	@${REINPLACE_CMD} -e 's|^SHELL =.*|SHELL=/bin/sh|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
