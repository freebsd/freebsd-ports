# Created by: Jordan DeLong <fracture@allusion.net>
# $FreeBSD$

PORTNAME=	prboom-plus
PORTVERSION=	2.5.1.3
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	thiagohero501@gmail.com
COMMENT=	Fork of the prboom Doom game engine

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsmpeg.so:multimedia/smpeg \
		libpng.so:graphics/png

USES=		gmake localbase
USE_SDL=	mixer net sdl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-waddir=${DATADIR}

OPTIONS_DEFINE=	OPENGL
OPTIONS_DEFAULT=OPENGL

DATADIR=	${DMDIR}

OPENGL_CONFIGURE_ENABLE=	gl
OPENGL_USE=	GL=yes

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} \
		-e '/^gamesdir/s|/games|/bin|' \
		-e '/^docdir/s/@PACKAGE@-@VERSION@/@PACKAGE@/'

.include "${.CURDIR}/Makefile.include"

.include <bsd.port.mk>
