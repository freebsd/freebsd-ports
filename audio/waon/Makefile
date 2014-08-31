# Created by: Kengo Ichiki <kichiki@users.sourceforge.net>
# $FreeBSD$

PORTNAME=	waon
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	kichiki@users.sourceforge.net
COMMENT=	Wave-to-Notes transcriber and some utility tools

LICENSE=	GPLv2

LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3 \
		libao.so:${PORTSDIR}/audio/libao \
		libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate

USES=		pkgconfig
USE_GNOME=	gtk20

PLIST_FILES=	bin/waon bin/pv bin/gwaon \
		man/man1/gwaon.1.gz man/man1/pv.1.gz man/man1/waon.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/waon \
		${WRKSRC}/pv \
		${WRKSRC}/gwaon ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/*.1  ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
