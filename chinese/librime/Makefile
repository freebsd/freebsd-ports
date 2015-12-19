# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	librime
PORTVERSION=	1.1
DISTVERSIONPREFIX=	rime-
CATEGORIES=	chinese textproc

MAINTAINER=	lichray@gmail.com
COMMENT=	Rime Input Method Engine, the core library

LICENSE=	GPLv3

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libglog.so:${PORTSDIR}/devel/glog \
		libkyotocabinet.so:${PORTSDIR}/databases/kyotocabinet \
		libopencc.so:${PORTSDIR}/chinese/opencc \
		libyaml-cpp.so:${PORTSDIR}/devel/yaml-cpp

USES=		cmake compiler:c++11-lib pkgconfig gettext perl5
USE_PERL5=	build patch
USE_LDCONFIG=	yes
USE_XORG=	xproto
LDFLAGS+=	-lintl
USE_GITHUB=	yes
GH_ACCOUNT=	rime

PLIST_SUB=	VER=${PORTVERSION}.0

BROKEN_powerpc64=	Does not build on powerpc64

.include <bsd.port.options.mk>

post-patch:     .SILENT
	${FIND} ${WRKSRC} \( -name '*.cc' -or -name '*.h' \) \
		-exec ${PERL} -i -pe '$$. == 1 && s/^\xef\xbb\xbf//;' '{}' \;

.include <bsd.port.mk>
