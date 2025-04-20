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

.include <bsd.port.pre.mk>

.if ${RUBY_VER} >= 3.3
BROKEN=	mmap.c:1108:24: error: no member named 'rmatch' in 'struct RMatch'
.endif

.if ${OPSYS} == FreeBSD
CONFIGURE_ARGS+=	--with-cflags="-Wno-error=incompatible-function-pointer-types"
.endif

.include <bsd.port.post.mk>
