PORTNAME=	concurrent-ruby-ext
PORTVERSION=	1.2.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C extensions to optimize the concurrent-ruby
WWW=		https://github.com/ruby-concurrency/concurrent-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-concurrent-ruby>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-concurrent-ruby

USES=		gem

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CONFIGURE_ARGS+=	--with-cflags="-Wno-error=int-conversion"
.endif

.include <bsd.port.mk>
