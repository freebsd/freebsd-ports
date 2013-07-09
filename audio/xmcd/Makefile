# Created by: Gennady Sorokopud <gena@NetVision.net.il>
# $FreeBSD$

PORTNAME=	xmcd
PORTVERSION=	3.3.2
PORTREVISION=	15
CATEGORIES=	audio
MASTER_SITES=	http://www.ibiblio.org/tkan/download/xmcd/3.3.2/src/

MAINTAINER=	eischen@vigrid.com
COMMENT=	Motif CD player

LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis \
		FLAC:${PORTSDIR}/audio/flac
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame

USES=		imake motif
USE_XORG=	x11 xext xaw xmu xp xpm xt sm ice
MAN1=		cda.1 xmcd.1
MANCOMPRESSED=	no
PLIST_SUB+=	RELEASE=${OSREL:R:R} ARCH=${ARCH}
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

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

post-install:
	@${STRIP_CMD} ${LIBBINDIR}/cda
	@${STRIP_CMD} ${LIBBINDIR}/gobrowser
	@${STRIP_CMD} ${LIBBINDIR}/has_alsa
	@${STRIP_CMD} ${LIBBINDIR}/xmcd
	@${CAT} ${PKGMESSAGE}
	@${CP} ${WRKSRC}/xmcd_d/XMcd.ad ${PREFIX}/lib/X11/app-defaults/XMcd

.include <bsd.port.mk>
