# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	bitkeeper
PORTVERSION=	7.3.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://www.bitkeeper.org/downloads/${PORTVERSION}/
DISTNAME=	bk-${PORTVERSION}.src

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Scalable Distributed Source Management System

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/gperf:devel/gperf \
		${LOCALBASE}/include/tommath.h:math/libtommath \
		bash:shells/bash
LIB_DEPENDS=    libtomcrypt.so:security/libtomcrypt \
		libpcre.so:devel/pcre	\
		liblz4.so:archivers/liblz4
RUN_DEPENDS=	bash:shells/bash

BROKEN_FreeBSD_11=	perl: No such file or directory

USES=		gmake groff bison localbase tk xorg iconv pkgconfig
USE_XORG=       x11

WRKSRC= ${WRKDIR}/bk-${PORTVERSION}/src
ALL_TARGET= p

do-build:
	@(cd ${WRKSRC}; ${MAKE_CMD} ${ALL_TARGET})

post-install:
	${LN} -s ../bitkeeper/bk ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
