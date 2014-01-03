# $FreeBSD$

PORTNAME=	hidapi
DISTVERSION=	0.8.0-rc1
CATEGORIES=	comms

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Library to access USB HID-class devices

LICENSE=	BSD3CLAUSE GPLv3
LICENSE_COMB=	dual

USE_GITHUB=	yes
GH_ACCOUNT=	signal11
GH_TAGNAME=	${PORTNAME}-${DISTVERSION}
GH_COMMIT=	40cf516

USE_AUTOTOOLS=	aclocal autoconf autoheader automake libtoolize
AUTOMAKE_ARGS=	--add-missing

USES=		iconv
USE_LDCONFIG=	yes

.include <bsd.port.mk>
