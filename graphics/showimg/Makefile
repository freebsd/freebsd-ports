# ex:ts=8
# Ports collection makefile for:	showimg
# Date created:			Mar 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	showimg
PORTVERSION=	0.8.0
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.jalix.org/projects/showimg/download/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A picture viewer designed to run under KDE 3.x

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_KDEBASE_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-xinerama

MAN1=		showimg.1

post-patch:
	@${REINPLACE_CMD} -e 's|-pedantic||g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
