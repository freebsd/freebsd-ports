# New ports collection makefile for:	mgetty+sendfax
# Version required:			1.1.21
# Date created:				20 April 1998
# Whom:					rkw
#
# $FreeBSD$
#

DISTNAME=	mgetty1.1.21-Jul24
PKGNAME=	mgetty-1.1.21
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.leo.org/pub/comp/os/unix/networking/mgetty/

MAINTAINER=	jmz@FreeBSD.org

WRKSRC=		${WRKDIR}/mgetty-1.1.21
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
	@(cd ${PKGDIR}; export PKG_PREFIX=${PREFIX}; ${PERL5} INSTALL _ POST-INSTALL)
.endif

.include <bsd.port.mk>
