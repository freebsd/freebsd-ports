# New ports collection makefile for:	mgetty+sendfax
# Date created:				20 April 1998
# Whom:					rkw
#
# $FreeBSD$
#

PORTNAME=	mgetty
PORTVERSION=	1.1.28.01.10
CATEGORIES=	comms
MASTER_SITES=	ftp://alpha.greenie.net/pub/mgetty/source/1.1/
DISTNAME=	mgetty1.1.28-Jan10

MAINTAINER=	jmz@FreeBSD.org

WRKSRC=		${WRKDIR}/mgetty-1.1.28
MAKE_FLAGS=	prefix=${PREFIX} -f
MAN1=		coverpg.1 \
		fax.1 \
		faxq.1 \
		faxrm.1 \
		faxrunq.1 \
		faxspool.1 \
		g3cat.1 \
		g32pbm.1 \
		lintopvf.1 \
		pbm2g3.1 \
		pvf.1 \
		zplay.1
MAN4=		mgettydefs.4
MAN5=		faxqueue.5
MAN8=		callback.8 \
		faxrunqd.8 \
		mgetty.8 \
		sendfax.8 \
		vgetty.8
MLINKS=		pvf.1 pvfamp.1 \
		pvf.1 pvfcut.1 \
		pvf.1 pvfecho.1 \
		pvf.1 pvffft.1 \
		pvf.1 pvffile.1 \
		pvf.1 pvffilter.1 \
		pvf.1 pvfmix.1 \
		pvf.1 pvfnoise.1 \
		pvf.1 pvfreverse.1 \
		pvf.1 pvfsine.1 \
		pvf.1 pvfspeed.1 \
		pvf.1 pvftoau.1 \
		pvf.1 pvftobasic.1 \
		pvf.1 pvftolin.1 \
		pvf.1 pvftormd.1 \
		pvf.1 pvftovoc.1 \
		pvf.1 pvftowav.1 \
		pvf.1 rmdfile.1 \
		pvf.1 rmdtopvf.1 \
		pvf.1 voctopvf.1 \
		pvf.1 wavtopvf.1

pre-install:
	@(cd ${WRKSRC}/doc; ${MAKE} manpages)

post-install:
	@${CP} ${PREFIX}/etc/mgetty+sendfax/dialin.config \
		${PREFIX}/etc/mgetty+sendfax/dialin.config.dist
	@${CP} ${PREFIX}/etc/mgetty+sendfax/faxheader \
		${PREFIX}/etc/mgetty+sendfax/faxheader.dist
	@${CP} ${PREFIX}/etc/mgetty+sendfax/faxrunq.config \
		${PREFIX}/etc/mgetty+sendfax/faxrunq.config.dist
	@${CP} ${PREFIX}/etc/mgetty+sendfax/login.config \
		${PREFIX}/etc/mgetty+sendfax/login.config.dist
	@${TAR}  -cf - -C ${WRKSRC} samples | ${TAR}  -xf - -C ${PREFIX}/lib/mgetty+sendfax/
	@install-info ${PREFIX}/info/mgetty.info ${PREFIX}/info/dir
.if !defined(BATCH)
	@(cd ${PKGDIR}; export PKG_PREFIX=${PREFIX}; ${PERL5} ${PKGINSTALL} _ POST-INSTALL)
.endif

.include <bsd.port.mk>
