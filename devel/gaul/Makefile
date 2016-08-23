# Created by: ijliao
# $FreeBSD$

PORTNAME=	gaul
PORTVERSION=	0.1849.0
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-devel/0.1849
DISTNAME=	${PORTNAME}-devel-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Genetic Algorithm Utility Library

LIB_DEPENDS=	libslang.so:devel/libslang2

USES=		gmake libtool ncurses tar:bzip2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lncurses
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
