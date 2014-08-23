# Created by: Jordan DeLong <fracture@allusion.net>
# $FreeBSD$

PORTNAME=	prboom-plus
PORTVERSION=	2.5.1.3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	thiagohero501@gmail.com
COMMENT=	A fork of the doom game engine prboom

LICENSE=	GPLv2

LIB_DEPENDS=	libsmpeg.so:${PORTSDIR}/multimedia/smpeg \
		libpng.so:${PORTSDIR}/graphics/png

CONFLICTS=	prboom-[2]*

USES=		gmake
USE_SDL=	mixer net sdl
NEED_ROOT=	yes

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-waddir=${DATADIR}

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
