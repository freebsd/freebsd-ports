# Created by: Carlos J Puga Medina <cpm@fbsd.es>
# $FreeBSD$

PORTNAME=	dnsdist
DISTVERSION=	0.0.281gade4ced
CATEGORIES=	dns net
MASTER_SITES=	http://builder.powerdns.com/files/dnsdist/dist/

MAINTAINER=	cpm@fbsd.es
COMMENT=	Highly DNS-, DoS- and abuse-aware loadbalancer

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libatomic_ops.a:${PORTSDIR}/devel/libatomic_ops \
		ragel>0:${PORTSDIR}/devel/ragel
LIB_DEPENDS=	libboost_serialization.so:${PORTSDIR}/devel/boost-libs \
		libsodium.so:${PORTSDIR}/security/libsodium

CXXFLAGS+=	-D_GLIBCXX_USE_C99
LDFLAGS+=	-L${LOCALBASE}/lib -latomic
GNU_CONFIGURE=	yes
USE_GCC=	yes
USES=		bison cpe gmake libtool lua:52 pkgconfig readline tar:bz2
CONFIGURE_ARGS=	--enable-libsodium
INSTALL_TARGET=	install-strip

USE_RC_SUBR=	dnsdist

post-install:
	${INSTALL_DATA} ${FILESDIR}/dnsdist.conf.sample \
		${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
