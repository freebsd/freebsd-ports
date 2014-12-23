# $FreeBSD$

PORTNAME=	hidapi
DISTVERSION=	0.8.0-rc1
PORTREVISION=	3
CATEGORIES=	comms

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Library to access USB HID-class devices

LICENSE=	BSD3CLAUSE GPLv3
LICENSE_COMB=	dual

USE_GITHUB=	yes
GH_ACCOUNT=	signal11
GH_TAGNAME=	${PORTNAME}-${DISTVERSION}
GH_COMMIT=	40cf516

USES=		autoreconf iconv:wchar_t libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
PORTDOCS=	*

.include <bsd.port.mk>
