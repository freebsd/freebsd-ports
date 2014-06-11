# $FreeBSD$

PORTNAME=	libfreehand
PORTVERSION=	0.0.0
CATEGORIES=	graphics
MASTER_SITES=	http://dev-www.libreoffice.org/src/
PKGNAMESUFFIX=	00

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library providing ability to interpret and import Adobe/Macromedia drawings

LICENSE=	LGPL21 MPL GPLv2
LICENSE_COMB=	dual

LIB_DEPENDS=	libwpd-0.9.so:${PORTSDIR}/textproc/libwpd \
		libwpg-0.2.so:${PORTSDIR}/graphics/libwpg

GNU_CONFIGURE=	yes
USES=	libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--without-docs --disable-werror
INSTALL_TARGET=	install-strip

post-install:
	@${RM} -f ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>

