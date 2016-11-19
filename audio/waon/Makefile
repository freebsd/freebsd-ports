# Created by: Kengo Ichiki <kichiki@users.sourceforge.net>
# $FreeBSD$

PORTNAME=	waon
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	kichiki@users.sourceforge.net
COMMENT=	Wave-to-Notes transcriber and some utility tools

LICENSE=	GPLv2

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libao.so:audio/libao \
		libsndfile.so:audio/libsndfile \
		libsamplerate.so:audio/libsamplerate

USES=		ncurses pkgconfig
USE_GNOME=	gtk20

PLIST_FILES=	bin/waon bin/pv bin/gwaon \
		man/man1/gwaon.1.gz man/man1/pv.1.gz man/man1/waon.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/waon \
		${WRKSRC}/pv \
		${WRKSRC}/gwaon ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/*.1  ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
