# New ports collection makefile for:	mgetty+sendfax
# Date created:				20 April 1998
# Whom:					rkw
#
# $FreeBSD$
#

PORTNAME=	mgetty
PORTVERSION=	1.1.35
PORTREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	ftp://mgetty.greenie.net/pub/mgetty/source/1.1/
DISTNAME=	${PORTNAME}${PORTVERSION}-Feb22

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Handle external logins, send and receive faxes

USE_PERL5=	yes

CONFLICTS=	netpbm-[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_FLAGS=	CFLAGS="${CFLAGS}" prefix=${PREFIX} -f
ALL_TARGET=	noident all
INFO=		mgetty
MAN1=		autopvf.1 \
		basictopvf.1 \
		coverpg.1 \
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
		sff2g3.1 \
		zplay.1
MAN4=		mgettydefs.4
MAN5=		faxqueue.5
MAN8=		callback.8 \
		faxq-helper.8 \
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

CFLAGS+=	-DAUTO_PPP
.if defined(WITH_FIDO) && ${WITH_FIDO:L} != no
CFLAGS+=	-DFIDO
.endif

pre-everything::
.if !defined(WITH_FIDO)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you need FIDO EMSI support, use \"make WITH_FIDO=yes\""
	@${ECHO_MSG}
.endif

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
	${INSTALL_DATA} -m 600 ${WRKSRC}/voice/voice.conf-dist \
		${PREFIX}/etc/mgetty+sendfax/voice.conf.dist
	@${TAR}  -cf - -C ${WRKSRC} samples | ${TAR}  -xf - -C ${PREFIX}/lib/mgetty+sendfax/
.if !defined(BATCH)
	@(cd ${PKGDIR}; export PKG_PREFIX=${PREFIX}; ${PERL5} ${PKGINSTALL} _ POST-INSTALL)
.endif

.include <bsd.port.mk>
