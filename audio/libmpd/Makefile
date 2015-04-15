# Created by: Stepan Zastupov [RedChrom] <redchrom@gmail.com>
# $FreeBSD$

PORTNAME=	libmpd
PORTVERSION=	11.8.17
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abstraction around libmpdclient

LICENSE=	GPLv2 # (or later)

USES=		libtool pathfix pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,libmpd-1.0\/libmpd,libmpd,' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
