# Created by: Stepan Zastupov [RedChrom] <redchrom@gmail.com>
# $FreeBSD$

PORTNAME=	libmpd
PORTVERSION=	11.8.17
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abstraction around libmpdclient

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome libtool pathfix pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,libmpd-1.0\/libmpd,libmpd,' \
		${WRKSRC}/src/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmpd.so

.include <bsd.port.mk>
