PORTNAME=	git-annex
DISTVERSION=	10.20261113
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Manage files with git, without checking their contents into git
WWW=		https://git-annex.branchable.com/ \
		https://hackage.haskell.org/package/git-annex

LICENSE=	AGPLv3+

MY_DEPENDS=	git:devel/git \
		rsync:net/rsync
BUILD_DEPENDS=	${MY_DEPENDS}
LIB_DEPENDS=	libbotan-3.so:security/botan3
RUN_DEPENDS=	${MY_DEPENDS}

USES=		cabal pkgconfig

CABAL_FLAGS=	assistant production magicmime torrentparser \
		-benchmark -debuglocks
CABAL_PROJECT=	remove

PLIST_FILES=	bin/git-annex-shell \
		bin/git-remote-tor-annex

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64
# compiler goes out of memory
BUILD_ARGS+=	--disable-optimization
.endif

post-stage:
	${RLN} git-annex ${STAGEDIR}${PREFIX}/bin/git-annex-shell
	${RLN} git-annex ${STAGEDIR}${PREFIX}/bin/git-remote-tor-annex

.include <bsd.port.post.mk>
