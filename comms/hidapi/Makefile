# $FreeBSD$

PORTNAME=	hidapi
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	0.10.1
CATEGORIES=	comms

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Library to access USB HID-class devices

LICENSE=	BSD3CLAUSE GPLv3
LICENSE_COMB=	dual

USES=		autoreconf gettext-tools iconv:wchar_t libtool localbase \
		pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	libusb

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

pre-configure:
	@${CP} ${LOCALBASE}/share/gettext/config.rpath ${WRKSRC}

.include <bsd.port.mk>
