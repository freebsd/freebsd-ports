# $FreeBSD$

PORTNAME=		Jellyfish
DISTVERSIONPREFIX=	v
DISTVERSION=		2.2.10
PORTREVISION=		8
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Fast, memory-efficient counting of k-mers in DNA

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	yaggo:devel/yaggo
LIB_DEPENDS=	libhts.so:biology/htslib

USES=		autoreconf compiler:c++11-lib gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
GH_ACCOUNT=	gmarcais

INSTALL_TARGET=	install-strip
PLIST_SUB=	VER=${PORTVERSION}

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.pre.mk>

# SSE code assumes amd64 features
.if ${ARCH} != "amd64"
CONFIGURE_ARGS+=--without-sse
.endif

.if ${CHOSEN_COMPILER_TYPE} == gcc
CXXFLAGS+=	-faligned-new
.endif

.include <bsd.port.post.mk>
