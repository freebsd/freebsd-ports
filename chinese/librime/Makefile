# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	librime
PORTVERSION=	1.2.9
DISTVERSIONPREFIX=	rime-
PORTREVISION=	20
CATEGORIES=	chinese textproc

MAINTAINER=	lichray@gmail.com
COMMENT=	Rime Input Method Engine, the core library

LICENSE=	GPLv3

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libleveldb.so:databases/leveldb \
		libmarisa.so:devel/marisa-trie \
		libopencc.so:chinese/opencc \
		libyaml-cpp.so:devel/yaml-cpp

USES=		cmake compiler:c++11-lib gettext pathfix perl5 pkgconfig xorg
USE_PERL5=	build patch

USE_CXXSTD=	c++11
USE_LDCONFIG=	yes
USE_XORG=	xorgproto
LDFLAGS+=	-lintl
USE_GITHUB=	yes
GH_ACCOUNT=	rime

PLIST_SUB=	VER=${PORTVERSION}

post-patch:
	@${FIND} ${WRKSRC} \( -name '*.cc' -or -name '*.h' \) \
		-exec ${PERL} -i -pe '$$. == 1 && s/^\xef\xbb\xbf//;' {} \;

.include <bsd.port.mk>
