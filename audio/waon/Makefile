# Created by: Kengo Ichiki <kichiki@users.sourceforge.net>
# $FreeBSD$

PORTNAME=	waon
PORTVERSION=	0.9
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	kichiki@users.sourceforge.net
COMMENT=	Wave-to-Notes transcriber and some utility tools

LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3 \
		libao.so:${PORTSDIR}/audio/libao \
		libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate

USES=		pkgconfig
NO_STAGE=	yes
USE_GNOME=	gtk20

MAN1=		waon.1 pv.1 gwaon.1
PLIST_FILES=	bin/waon bin/pv bin/gwaon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/waon  ${PREFIX}/bin/waon
	${INSTALL_PROGRAM} ${WRKSRC}/pv    ${PREFIX}/bin/pv
	${INSTALL_PROGRAM} ${WRKSRC}/gwaon ${PREFIX}/bin/gwaon
	${INSTALL_MAN} ${WRKSRC}/waon.1  ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/pv.1    ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/gwaon.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
