# New ports collection makefile for:	mgetty+sendfax
# Date created:				20 April 1998
# Whom:					rkw
#
# $FreeBSD$
#

PORTNAME=	mgetty
PORTVERSION=	1.1.25.02.01
CATEGORIES=	comms
MASTER_SITES=	ftp://alpha.greenie.net/pub/mgetty/source/1.1/
DISTNAME=	mgetty1.1.25-Feb01

MAINTAINER=	jmz@FreeBSD.org

WRKSRC=		${WRKDIR}/mgetty-1.1.25
MAKE_FLAGS=	prefix=${PREFIX} -f
MAN1=		coverpg.1 \
		fax.1 \
		faxq.1 \
		faxrm.1 \
		faxrunq.1 \
		faxspool.1 \
		g3cat.1 \
		g32pbm.1 \
		pbm2g3.1 \
		pvf.1 \
		zplay.1
MAN4=		mgettydefs.4
MAN5=		faxqueue.5
MAN8=		callback.8 \
		faxrunqd.8 \
		mgetty.8 \
		sendfax.8

pre-install:
	@(cd ${WRKSRC}/doc; ${MAKE} manpages)

.if !defined(BATCH)
post-install:
	@(cd ${PKGDIR}; export PKG_PREFIX=${PREFIX}; ${PERL5} ${PKGINSTALL} _ POST-INSTALL)
.endif

.include <bsd.port.mk>
