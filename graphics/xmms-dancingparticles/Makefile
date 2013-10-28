# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	dancingparticles
PORTVERSION=	0.6
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	http://tardyp.free.fr/dancingparticles/
PKGNAMEPREFIX=	xmms-
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Makes particles dance with pretty neon colors

LIB_DEPENDS=	t1.5:${PORTSDIR}/devel/t1lib \
		xmms.4:${PORTSDIR}/multimedia/xmms

USE_GL=		glut
USE_GNOME=	gtk12
USE_SDL=	sdl
CFLAGS+=	-I${PREFIX}/include

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|\(#include.*\)SDL/\(SDL.*\)|\1\2| ; \
		s|/usr/local|${PREFIX}|' ${WRKSRC}/*.cc ${WRKSRC}/*.h

.include <bsd.port.mk>
