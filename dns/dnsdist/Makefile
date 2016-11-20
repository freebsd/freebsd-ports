# Created by: Carlos J Puga Medina <cpm@fbsd.es>
# $FreeBSD$

PORTNAME=	dnsdist
DISTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	dns net
MASTER_SITES=	https://downloads.powerdns.com/releases/ \
		LOCAL/cpm

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Highly DNS-, DoS- and abuse-aware loadbalancer

LICENSE=	GPLv2 UNLICENSE
LICENSE_COMB=	multi
LICENSE_NAME_UNLICENSE=	The Unlicense
LICENSE_FILE_UNLICENSE=	${WRKSRC}/ext/incbin/UNLICENSE
LICENSE_PERMS_UNLICENSE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${LOCALBASE}/lib/libatomic_ops.a:devel/libatomic_ops
LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libsodium.so:security/libsodium

CXXFLAGS+=	-D_GLIBCXX_USE_C99
LDFLAGS+=	-L${LOCALBASE}/lib -latomic
GNU_CONFIGURE=	yes
USE_GCC=	yes
USES=		bison cpe gmake libedit libtool lua:52 pkgconfig tar:bz2
CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin --enable-dnscrypt --enable-libsodium --without-protobuf
INSTALL_TARGET=	install-strip

USERS=		_dnsdist
GROUPS=		_dnsdist

USE_RC_SUBR=	dnsdist

post-install:
	${INSTALL_DATA} ${FILESDIR}/dnsdist.conf.sample \
		${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
