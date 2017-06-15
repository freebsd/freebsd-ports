# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	liquidwar
PORTVERSION=	5.6.4
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://liquidwar.sunsite.dk/archive/ \
		SAVANNAH \
		http://ufoot.hd.free.fr/pub/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	You control an army of liquid and have to try and eat your opponents

LIB_DEPENDS=	liballeg.so:devel/allegro

GNU_CONFIGURE=	yes
USES=		gmake makeinfo python:build
CONFIGURE_ARGS=	--disable-target-opt --disable-doc-ps --disable-doc-pdf
CONFIGURE_ENV=	ac_cv_prog_PYTHON=yes

INFO=		liquidwar

OPTIONS_DEFINE=		ASM

ASM_CONFIGURE_OFF=	--disable-asm

post-patch:
	@${REINPLACE_CMD} 's,python,${PYTHON_CMD},' ${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
