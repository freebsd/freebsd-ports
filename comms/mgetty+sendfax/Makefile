# New ports collection makefile for:    mgetty+sendfax
# Version required:     0.99
# Date created:         21 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.15 1996/11/22 11:03:01 asami Exp $
#

DISTNAME=	mgetty-0.99
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.leo.org/pub/comp/networking/communication/modem/mgetty/
DISTFILES=	mgetty099-Aug07.tar.gz

MAINTAINER=	jmz@FreeBSD.org

MAKE_FLAGS=	prefix=${PREFIX} -f 
MAN1=		coverpg.1 fax.1 faxq.1 faxrm.1 faxrunq.1 faxspool.1 \
		g3cat.1 g3topbm.1 pbmtog3.1
MAN4=		mgettydefs.4
MAN5=		faxqueue.5
MAN8=		sendfax.8 mgetty.8 callback.8

pre-install:
	@(cd ${WRKSRC}/doc; ${GMAKE} manpages)

.if !defined(BATCH)
post-install:
	@(cd ${PKGDIR}; export PKG_PREFIX=${PREFIX}; /usr/bin/perl INSTALL _ POST-INSTALL)
.endif

.include <bsd.port.mk>
