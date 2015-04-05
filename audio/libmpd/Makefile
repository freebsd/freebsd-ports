# Created by: Stepan Zastupov [RedChrom] <redchrom@gmail.com>
# $FreeBSD$

PORTNAME=	libmpd
PORTVERSION=	11.8.17
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/11.8.16/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abstraction around libmpdclient

BROKEN=		Unfetchable
GNU_CONFIGURE=	yes
USES=		libtool pathfix pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,libmpd-1.0\/libmpd,libmpd,' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
