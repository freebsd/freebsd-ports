# Created by: Carlos J Puga Medina <cpm@fbsd.es>
# $FreeBSD$

PORTNAME=	dnsdist
DISTVERSION=	0.0.209g4fd8aed
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
USE_GCC=	4.8+
USES=	bison gmake libtool lua:52 pkgconfig readline tar:bz2
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/dnsdist \
		man/man1/dnsdist.1.gz

.include <bsd.port.mk>
