# Created by: David Sugar <dyfet@gnu.org>
# $FreeBSD$

PORTNAME=	commoncpp
PORTVERSION=	1.8.1
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	devel
MASTER_SITES=	GNU
DISTNAME=	${PORTNAME:S/$/2/}-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	GNU project portable class framework for C++

USE_LDCONFIG=	yes
USES=		gmake libtool pathfix ssl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_DOXYGEN=no
INSTALL_TARGET=	install-strip

INFO=		commoncpp2

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
