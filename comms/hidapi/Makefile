# $FreeBSD$

PORTNAME=	hidapi
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	0.8.0-rc1
PORTREVISION=	3
CATEGORIES=	comms

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Library to access USB HID-class devices

LICENSE=	BSD3CLAUSE GPLv3
LICENSE_COMB=	dual

USE_GITHUB=	yes
GH_ACCOUNT=	signal11

USES=		autoreconf gettext-tools iconv:wchar_t libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
PORTDOCS=	*

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

pre-configure:
	@${CP} ${LOCALBASE}/share/gettext/config.rpath ${WRKSRC}

.include <bsd.port.mk>
