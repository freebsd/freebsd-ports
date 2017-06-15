# $FreeBSD$

PORTNAME=	libunistring
PORTVERSION=	0.9.7
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	takefu@airport.fm
COMMENT=	Unicode string library

LICENSE=	GPLv2 LGPL3+
LICENSE_COMB=	dual
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LIB

USES=		alias charsetfix gmake iconv libtool tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
INFO=		${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
