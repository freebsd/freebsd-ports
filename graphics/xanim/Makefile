# New ports collection makefile for:	xanim
# Date created:         Sat Nov 5 11:43:03 PST 1994
# Whom:                 piero
#
# $FreeBSD$
#

PORTNAME=	xanim
PORTVERSION=	2.80.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://xanim.va.pubnix.com/ \
		ftp://xanim.va.pubnix.com/dlls/
DISTNAME=	xanim2801
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${EXTRA_FILES}

PATCH_SITES=	http://virtual-estates.net/port-stuff/
PATCHFILES=	xanim-2801-to-2802-patch.gz

MAINTAINER=	ports@FreeBSD.org

.if (${MACHINE_ARCH} == "i386")
EXTRA_FILES=	vid_cvid_2.1_freebsdELFx86.tgz \
		vid_cyuv_1.0_freebsdELFx86.tgz \
		vid_h261_1.0_freebsdELFx86.tgz \
		vid_h263_1.0_freebsdELFx86.tgz \
		vid_iv32_2.1_freebsdELFx86.tgz \
		vid_iv41_1.1_freebsdELFx86.tgz \
		vid_iv50_1.0_freebsdELFx86.tgz

DLLDIR=		${PREFIX}/lib/X11/xanim

PLIST_SUB+=	CODECS=""

.else

PLIST_SUB+=	CODECS="@comment "

.endif

USE_IMAKE=	yes
MAN1=		xanim.1

MAKE_ARGS+=	-j 2 # safe and helps even the single-CPU machines

post-extract:
	${CP} ${WRKSRC}/docs/xanim.man ${WRKSRC}

.if (${MACHINE_ARCH} == "i386")
post-install:
	@${MKDIR} ${DLLDIR}
	${INSTALL_DATA} ${WRKDIR}/*.readme ${DLLDIR}
	${INSTALL_DATA} ${WRKDIR}/*.xa ${DLLDIR}
.endif

.include <bsd.port.mk>
