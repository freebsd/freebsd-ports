# $FreeBSD$

PORTNAME=		shards
DISTVERSIONPREFIX=	v
DISTVERSION=		0.9.0
PORTREVISION=		2
CATEGORIES=		devel

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Dependency manager for the Crystal programming language

LICENSE=	APACHE20

BUILD_DEPENDS=	crystal:lang/crystal
LIB_DEPENDS=	libyaml.so:textproc/libyaml \
		libpcre.so:devel/pcre \
		libgc-threaded.so:devel/boehm-gc-threaded \
		libevent.so:devel/libevent
RUN_DEPENDS=	git:devel/git

USE_GITHUB=	yes
GH_ACCOUNT=	crystal-lang

MAKE_ARGS+=	CRFLAGS="--release --no-debug" \
		MANDIR="${STAGEDIR}${PREFIX}/man"

PLIST_FILES=	bin/shards \
		man/man1/shards.1.gz \
		man/man5/shard.yml.5.gz

.include <bsd.port.mk>
