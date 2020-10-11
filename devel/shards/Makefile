# $FreeBSD$

PORTNAME=		shards
DISTVERSIONPREFIX=	v
DISTVERSION=		0.12.0
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

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	crystal-lang
GH_TUPLE=	crystal-lang:crystal-molinillo:e61b200edb735d5676e11cbe56e8353c8b2ced0b:molinillo/lib/molinillo

MAKE_ARGS+=	CRYSTAL="${LOCALBASE}/bin/crystal" \
		FLAGS="--release --no-debug" \
		MANDIR="${STAGEDIR}${PREFIX}/man"

PLIST_FILES=	bin/shards \
		man/man1/shards.1.gz \
		man/man5/shard.yml.5.gz

.include <bsd.port.mk>
