# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	jellyfish
PORTVERSION=	2.2.4
DISTVERSIONPREFIX=	v
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Fast, memory-efficient counting of k-mers in DNA

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	yaggo:devel/yaggo

GNU_CONFIGURE=	yes

USES=		autoreconf compiler:c++11-lib gmake \
		libtool pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	gmarcais
GH_PROJECT=	Jellyfish

INSTALL_TARGET=	install-strip

BROKEN_FreeBSD_9_i386=	multiple code issues on i386 < 10.0-RELEASE

.include <bsd.port.pre.mk>

# SSE code assumes amd64 features
.if ${ARCH} != "amd64"
CONFIGURE_ARGS+=--without-sse
.endif

# configure does not support --with-pkgconfigdir
post-patch:
	@${REINPLACE_CMD} \
		-e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.am

.include <bsd.port.post.mk>
