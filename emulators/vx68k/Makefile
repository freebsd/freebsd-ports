# ex:ts=8
# Ports collection makefile for:	vx68k
# Date created:			Jun 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vx68k
PORTVERSION=	1.1.10
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.hypercore.co.jp/vx68k/${PORTNAME}-${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	vm68k:${PORTSDIR}/emulators/libvm68k

USE_BISON=	yes
USE_MESA=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lGL -lGLU -lglut ${PTHREAD_LIBS}"

MAN1=	vx68k.1

post-patch:
	@${PERL} -pi -e "s,Bison ,Bison,g" ${WRKSRC}/vx68k-gtk/configure

.include <bsd.port.mk>
