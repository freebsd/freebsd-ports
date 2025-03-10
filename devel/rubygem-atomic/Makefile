PORTNAME=	atomic
PORTVERSION=	1.1.101
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Atomic reference implementation
WWW=		https://github.com/ruby-concurrency/atomic

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem

CONFIGURE_ARGS=	--with-cflags=-Wno-int-conversion

.include <bsd.port.mk>
