PORTNAME=	mmap2
PORTVERSION=	2.2.9
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Implement memory-mapped file objects for Ruby 2.x
WWW=		https://gitlab.com/lyda/mmap

LICENSE=	RUBY

USES=		gem

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CONFIGURE_ARGS+=	--with-cflags="-Wno-error=incompatible-function-pointer-types"
.endif

.include <bsd.port.mk>
