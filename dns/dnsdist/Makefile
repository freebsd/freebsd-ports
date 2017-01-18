# Created by: Carlos J Puga Medina <cpm@fbsd.es>
# $FreeBSD$

PORTNAME=	dnsdist
DISTVERSION=	1.1.0
PORTREVISION=	1
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
		libprotobuf.so:devel/protobuf \
		libre2.so:devel/re2 \
		libsodium.so:security/libsodium

GNU_CONFIGURE=	yes
USES=		bison compiler:c++14-lang cpe gmake libedit libtool localbase \
		lua:52 pkgconfig tar:bz2
CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin \
		--enable-dnscrypt \
		--enable-libsodium \
		--enable-re2

INSTALL_TARGET=	install-strip

USERS=		_dnsdist
GROUPS=		_dnsdist

USE_RC_SUBR=	dnsdist

post-install:
	${INSTALL_DATA} ${FILESDIR}/dnsdist.conf.sample \
		${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
