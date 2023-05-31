PORTNAME=	guile-lib
PORTVERSION=	0.2.6.1
PORTREVISION=	2
CATEGORIES=	devel scheme
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Repository of useful code written in Guile Scheme
WWW=		https://www.nongnu.org/guile-lib/

LICENSE=	LGPL3 GPLv3
LICENSE_COMB=	multi

BUILD_DEPENDS=	guile2>0:lang/guile2
RUN_DEPENDS=	guile2>0:lang/guile2

TEST_TARGET=	check
USES=		gmake pkgconfig
GNU_CONFIGURE=	yes

INFO=	guile-library

.include <bsd.port.mk>
