# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	extace
PORTVERSION=	1.9.9
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/eXtace/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audio visualization plugin for the X Window System

LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		libtool pathfix pkgconfig
USE_GNOME=	esound gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm

PLIST_FILES=	bin/extace \
		share/gnome/apps/Multimedia/extace.desktop

post-patch:
	@${REINPLACE_CMD} '/^CFLAGS="-O2/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} '/^LIBS =/s/$$/ @LIBS@/' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
