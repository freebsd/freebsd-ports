PORTNAME=	rblineprof
PORTVERSION=	0.3.7
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Shows you lines of code that are slow
WWW=		https://github.com/tmm1/rblineprof

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgmp.so:math/gmp
RUN_DEPENDS=	rubygem-debugger-ruby_core_source>=1.3:devel/rubygem-debugger-ruby_core_source

USES=		gem

.include <bsd.port.mk>
