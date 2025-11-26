PORTNAME=	librime
DISTVERSION=	1.15.0
CATEGORIES=	chinese textproc

MAINTAINER=	eric@camachat.org
COMMENT=	Rime Input Method Engine, the core library
WWW=		https://rime.github.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libleveldb.so:databases/leveldb \
		libmarisa.so:devel/marisa-trie \
		libopencc.so:chinese/opencc \
		libyaml-cpp.so:devel/yaml-cpp

USES=		cmake compiler:c++17-lang perl5 pathfix pkgconfig xorg
USE_PERL5=	build patch
USE_XORG=	xorgproto
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rime

PLIST_SUB=	VER=${DISTVERSION}

CMAKE_OFF=	CMAKE_CXX_EXTENSIONS \
		BUILD_TEST

post-patch:
	@${FIND} ${WRKSRC} \( -name '*.cc' -or -name '*.h' \) \
		-exec ${PERL} -i -pe '$$. == 1 && s/^\xef\xbb\xbf//;' {} \;

.include <bsd.port.mk>
