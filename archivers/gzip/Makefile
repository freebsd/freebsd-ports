# New ports collection makefile for:	gzip
# Date created:				27 July 2002
# Whom:					cyrille.lefevre@laposte.net
#
# $FreeBSD$
#

PORTNAME=	gzip
PORTVERSION=	1.3.5
PORTREVISION=	1
CATEGORIES=	archivers
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
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	cyrille.lefevre@laposte.net
COMMENT=	A compression utility designed to be a replacement for compress

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=	gunzip.1 gzexe.1 gzip.1 zcat.1 zcmp.1 zdiff.1 zforce.1 \
	zgrep.1 zless.1 zmore.1 znew.1
INFO=	gzip

DOC_FILES=	AUTHORS COPYING INSTALL NEWS README README-alpha \
		THANKS TODO

post-configure:
	@${REINPLACE_CMD} -e 's|^SHELL =.*|SHELL=/bin/sh|' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
