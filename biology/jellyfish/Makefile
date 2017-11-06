# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	jellyfish
PORTVERSION=	2.2.6
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Fast, memory-efficient counting of k-mers in DNA

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	yaggo:devel/yaggo

GNU_CONFIGURE=	yes

USES=		autoreconf compiler:c++11-lib gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	gmarcais
GH_PROJECT=	Jellyfish

INSTALL_TARGET=	install-strip

PLIST_SUB=	VER=${PORTVERSION}

BROKEN_aarch64=		Fails to compile: error: variable res is uninitialized

.include <bsd.port.pre.mk>

# SSE code assumes amd64 features
.if ${ARCH} != "amd64"
CONFIGURE_ARGS+=--without-sse
.endif

.include <bsd.port.post.mk>
