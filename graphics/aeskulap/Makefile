# Created by: gahr
# $FreeBSD$

PORTNAME=	aeskulap
PORTVERSION=	0.2.1
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.bms-austria.com/%7Epipelka/${PORTNAME}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Medical image viewer

LICENSE=	GPLv2

LIB_DEPENDS=	libglademm-2.4.so:${PORTSDIR}/devel/libglademm24

USES=		gettext libtool pkgconfig
USE_GNOME=	gconfmm26 gtkmm24
GCONF_SCHEMAS=	aeskulap.schemas
USE_LDCONFIG=	${PREFIX}/lib/aeskulap

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
