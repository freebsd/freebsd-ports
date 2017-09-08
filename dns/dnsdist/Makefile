# Created by: Carlos J Puga Medina <cpm@fbsd.es>
# $FreeBSD$

PORTNAME=	dnsdist
DISTVERSION=	1.2.0
CATEGORIES=	dns net
MASTER_SITES=	https://downloads.powerdns.com/releases/ \
		LOCAL/cpm

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Highly DNS-, DoS- and abuse-aware loadbalancer

LICENSE=	GPLv2 UNLICENSE
LICENSE_COMB=	multi
LICENSE_FILE_UNLICENSE=	${WRKSRC}/ext/incbin/UNLICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libatomic_ops.a:devel/libatomic_ops
LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libprotobuf.so:devel/protobuf \
		libre2.so:devel/re2 \
		libsodium.so:security/libsodium

GNU_CONFIGURE=	yes
USES=		bison compiler cpe gmake libedit libtool localbase lua:52 \
		pkgconfig tar:bz2
CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin \
		--enable-dnscrypt \
		--enable-libsodium \
		--enable-re2

INSTALL_TARGET=	install-strip

USERS=		_dnsdist
GROUPS=		_dnsdist

USE_RC_SUBR=	dnsdist

.include <bsd.port.pre.mk>

# Fix dnsdist binaries when building on FreeBSD 10.3
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1100000
BUILD_DEPENDS+=	clang40:devel/llvm40
CC=		clang40
CXX=		clang++40
.endif

post-install:
	${INSTALL_DATA} ${FILESDIR}/dnsdist.conf.sample \
		${STAGEDIR}${PREFIX}/etc

.include <bsd.port.post.mk>
