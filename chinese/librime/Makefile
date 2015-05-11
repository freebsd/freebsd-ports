# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	librime
PORTVERSION=	1.1
CATEGORIES=	chinese textproc
MASTER_SITES=	http://github.com/rime/${PORTNAME}/archive/rime-${PORTVERSION}.tar.gz?dummy=/
DISTNAME=	${PORTNAME}-rime-${DISTVERSION}

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

PLIST_SUB=	VER=${PORTVERSION}.0

.include <bsd.port.options.mk>

post-patch:     .SILENT
	${FIND} ${WRKSRC} \( -name '*.cc' -or -name '*.h' \) \
		-exec ${PERL} -i -pe '$$. == 1 && s/^\xef\xbb\xbf//;' '{}' \;

.include <bsd.port.mk>
