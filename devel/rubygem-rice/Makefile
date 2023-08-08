PORTNAME=	rice
PORTVERSION=	4.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	C++ interface to Rubys C API
WWW=		https://github.com/jasonroelofs/rice

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_12_powerpc64=	fails to configure: could not find ruby.h

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
