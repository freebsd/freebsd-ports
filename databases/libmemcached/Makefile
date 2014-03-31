# $FreeBSD$

PORTNAME=	libmemcached
PORTVERSION=	1.0.7
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://launchpad.net/${PORTNAME}/1.0/${PORTVERSION}/+download/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	C and C++ client library to the memcached server

LIB_DEPENDS?=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libevent-1.4.so:${PORTSDIR}/devel/libevent

USES=		gmake pathfix pkgconfig perl5
USE_PERL5=	build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-memcached
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib -lexecinfo"
CXXFLAGS+=	-D__STDC_CONSTANT_MACROS

OPTIONS_DEFINE=	SASL

SASL_LIB_DEPENDS=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2

post-patch:
	@${REINPLACE_CMD} -e 's|^pkgconfigdir.*|pkgconfigdir = $${PREFIX}/libdata/pkgconfig|' \
			 -e '/^LDFLAGS *=/ s/$$/ $${LTLIBSASL2}/' \
			${WRKSRC}/Makefile.in ${WRKSRC}/support/include.am

.include <bsd.port.mk>
