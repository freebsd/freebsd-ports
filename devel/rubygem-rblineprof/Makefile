# $FreeBSD$

PORTNAME=	rblineprof
PORTVERSION=	0.3.7
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Shows you lines of code that are slow

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libunwind.so:devel/libunwind \
		libgmp.so:math/gmp
RUN_DEPENDS=	rubygem-debugger-ruby_core_source>=1.3:devel/rubygem-debugger-ruby_core_source

USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
