# Created by: gahr
# $FreeBSD$

PORTNAME=	aeskulap
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.bms-austria.com/%7Epipelka/${PORTNAME}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Medical image viewer

LICENSE=	GPLv2

LIB_DEPENDS=	libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24 \
    		libglademm-2.4.so:${PORTSDIR}/devel/libglademm24 \
		libgconfmm-2.6.so:${PORTSDIR}/devel/gconfmm26

USES=		gettext pkgconfig
USE_GNOME=	gconf2
GCONF_SCHEMAS=	aeskulap.schemas
USE_LDCONFIG=	${PREFIX}/lib/aeskulap

CXXFLAGS+=	-fPIC \
		-I${LOCALBASE}/include
GNU_CONFIGURE=	yes

post-install:
	${LN} -s libimagepool.so.0.0 ${STAGEDIR}${PREFIX}/lib/aeskulap/libimagepool.so
	${LN} -s libconfiguration.so.0.0 ${STAGEDIR}${PREFIX}/lib/aeskulap/libconfiguration.so

.include <bsd.port.mk>
