# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	extace
PORTVERSION=	1.9.9
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/eXtace/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audio visualization plugin for the X Window System

LICENSE=	GPLv2

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libesd.so:audio/esound

USES=		compiler:c++11-lang gnome libtool localbase pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
LIBS+=		-lm

PLIST_FILES=	bin/extace \
		share/gnome/apps/Multimedia/extace.desktop

post-patch:
	@${REINPLACE_CMD} '/^CFLAGS="-O2/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} '/^LIBS =/s/$$/ @LIBS@/' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
