PORTNAME=	librime
PORTVERSION=	1.7.3
PORTREVISION=	9
CATEGORIES=	chinese textproc

PATCH_SITES=	https://github.com/rime/librime/commit/
PATCHFILES=	c34c9ea4069bdba9d0f829e615769d79549701a9.patch:-p1

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Rime Input Method Engine, the core library
WWW=		https://rime.github.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libcapnp.so:devel/capnproto \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libleveldb.so:databases/leveldb \
		libmarisa.so:devel/marisa-trie \
		libopencc.so:chinese/opencc \
		libyaml-cpp.so:devel/yaml-cpp \

USES=		cmake compiler:c++14-lang gettext pathfix perl5 pkgconfig xorg
USE_PERL5=	build patch

CMAKE_OFF=	BUILD_TEST

USE_CXXSTD=	c++14
USE_LDCONFIG=	yes
USE_XORG=	xorgproto
CXXFLAGS+=	-DGLOG_USE_GLOG_EXPORT
LDFLAGS+=	-lintl
USE_GITHUB=	yes
GH_ACCOUNT=	rime

PLIST_SUB=	VER=${PORTVERSION}

post-patch:
	@${FIND} ${WRKSRC} \( -name '*.cc' -or -name '*.h' \) \
		-exec ${PERL} -i -pe '$$. == 1 && s/^\xef\xbb\xbf//;' {} \;

.include <bsd.port.mk>
