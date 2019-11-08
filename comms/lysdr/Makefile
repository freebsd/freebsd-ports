# $FreeBSD$

PORTNAME=	lysdr
PORTVERSION=	0.0.6
PORTREVISION=	2
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Lysdr SDR program for Unix

LICENSE=	GPLv2

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libjack.so:audio/jack

USE_GITHUB=	yes
GH_ACCOUNT=	gordonjcp
GH_TAGNAME=	stable-0

USES=		gnome pkgconfig
USE_GNOME=	gtk20
PLIST_FILES=	bin/lysdr

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/lysdr ${STAGEDIR}${PREFIX}/bin/lysdr

.include <bsd.port.mk>
