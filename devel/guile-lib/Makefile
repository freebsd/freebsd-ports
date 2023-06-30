PORTNAME=	guile-lib
PORTVERSION=	0.2.7
CATEGORIES=	devel scheme
MASTER_SITES=	SAVANNAH

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Repository of useful code written in Guile Scheme
WWW=		https://www.nongnu.org/guile-lib/

LICENSE=	LGPL3 GPLv3
LICENSE_COMB=	multi

BUILD_DEPENDS=	guile2>=2.0.12:lang/guile2
LIB_DEPENDS=	libguile-2.2.so:lang/guile2

USES=		gmake pkgconfig

GNU_CONFIGURE=	yes
TEST_TARGET=	check

INFO=		guile-library

.include <bsd.port.mk>
