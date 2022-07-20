PORTNAME=	commoncpp
PORTVERSION=	1.8.1
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	devel
MASTER_SITES=	GNU
DISTNAME=	${PORTNAME}2-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	GNU project portable class framework for C++

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool localbase:ldflags pathfix ssl
USE_LDCONFIG=	yes
USE_CXXSTD=	c++98
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_DOXYGEN=no
INSTALL_TARGET=	install-strip

INFO=		commoncpp2

.include <bsd.port.mk>
