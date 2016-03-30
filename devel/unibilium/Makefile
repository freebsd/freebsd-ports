# Created by: Anton Tornqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	unibilium
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unibilium is a very basic terminfo library

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LGPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	mauke

USES=		gmake libtool:build perl5 pkgconfig
USE_PERL5=	build
USE_LDCONFIG=	yes
MAKE_ARGS=	MANDIR=${MANPREFIX}/man

post-patch:
	${REINPLACE_CMD} -e 's|$$(LIBDIR)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libunibilium.so

.include <bsd.port.mk>
