# New ports collection makefile for:	xmcd
# Date created:		16 February 1995
# Whom:			Gennady Sorokopud <gena@NetVision.net.il>
#
# $FreeBSD$
#

PORTNAME=	xmcd
PORTVERSION=	3.3.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.ibiblio.org/tkan/download/xmcd/3.3.2/src/

MAINTAINER=	eischen@vigrid.com
COMMENT=	Motif CD player

LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis \
		FLAC.7:${PORTSDIR}/audio/flac
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame

USE_REINPLACE=	yes
USE_MOTIF=	yes
USE_IMAKE=	yes
PLIST_SUB+=	RELEASE=${OSREL:R:R} ARCH=${ARCH}

MAN1=		cda.1 xmcd.1
MANCOMPRESSED=	no
RMAN=		${X11BASE}/bin/rman

.include <bsd.port.pre.mk>

LIBBINDIR=	${PREFIX}/lib/X11/xmcd/bin-FreeBSD_${OSREL:R:R}-${ARCH}

post-extract:
	@${CHMOD} -R u+w ${WRKSRC}

pre-patch:
	@${CP} ${WRKSRC}/xmcd_d/XMcd.ad ${WRKSRC}/xmcd_d/XMcd.ad.in

post-patch:
	@${SED} -e "s;@PREFIX@;${PREFIX};g" ${WRKSRC}/xmcd_d/XMcd.ad.in \
		> ${WRKSRC}/xmcd_d/XMcd.ad
	@${FIND} ${WRKSRC} -name Makefile -o -name Imakefile | \
		${XARGS} ${REINPLACE_CMD} \
		-e 's|_CFLAGS= -pthread|_CFLAGS= ${PTHREAD_CFLAGS}|g; \
		s|_LDFLAGS= -pthread|_LDFLAGS= ${PTHREAD_LIBS}|g'

.if ${X_WINDOW_SYSTEM:L} != xfree86-3
post-build:
	(cd ${WRKSRC}; \
	 for i in xmcd cda; do \
		${RM} -f $${i}-1.html; \
		${RMAN} -f HTML < $${i}_d/$${i}.man > $${i}-1.html && \
			${MV} $${i}-1.html $${i}.1.html; \
	 done)
.endif

post-install:
	@${STRIP_CMD} ${LIBBINDIR}/cda
	@${STRIP_CMD} ${LIBBINDIR}/gobrowser
	@${STRIP_CMD} ${LIBBINDIR}/has_alsa
	@${STRIP_CMD} ${LIBBINDIR}/xmcd
	@${CAT} ${PKGMESSAGE}
	@${CP} ${WRKSRC}/xmcd_d/XMcd.ad ${PREFIX}/lib/X11/app-defaults/XMcd
.if ${X_WINDOW_SYSTEM:L} != xfree86-3
	(cd ${WRKSRC}; \
	 for i in xmcd cda; do \
		${INSTALL_MAN} $${i}.1.html ${PREFIX}/lib/X11/doc/html; \
	 done)
.endif

.include <bsd.port.post.mk>
