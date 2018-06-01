# $FreeBSD$

PORTNAME=		shards
DISTVERSIONPREFIX=	v
DISTVERSION=		0.7.2
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

PLIST_FILES=	bin/shards \
		man/man1/shards.1.gz \
		man/man5/shard.yml.5.gz

do-build:
	cd ${WRKSRC} && crystal build --release --no-debug -o bin/shards src/shards.cr

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/shards ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${INSTALL_WRKSRC}/src/man/shards.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${INSTALL_WRKSRC}/src/man/shard.yml.5 ${STAGEDIR}${MANPREFIX}/man/man5/

.include <bsd.port.mk>
