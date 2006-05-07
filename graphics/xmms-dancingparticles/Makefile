# New ports collection makefile for:	xmms-dancingparticles
# Date created:				14 Oct 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	dancingparticles
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://tardyp.free.fr/dancingparticles/
PKGNAMEPREFIX=	xmms-
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Makes particles dance with very pretty neon colors

LIB_DEPENDS=	t1.5:${PORTSDIR}/devel/t1lib \
		glut.4:${PORTSDIR}/graphics/libglut \
		xmms.4:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_GL=		yes
USE_GNOME=	gtk12
USE_SDL=	sdl
CFLAGS+=	-I${PREFIX}/include

post-patch:
	@${REINPLACE_CMD} -e 's|\(#include.*\)SDL/\(SDL.*\)|\1\2| ; \
		s|/usr/local|${PREFIX}|' ${WRKSRC}/*.cc ${WRKSRC}/*.h

.include <bsd.port.mk>
