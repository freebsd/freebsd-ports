# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uatraits
PORTVERSION=	20130430
PORTREVISION=	12
CATEGORIES=	devel www
MASTER_SITES=	http://people.freebsd.org/~demon/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	User-Agent detection library

BROKEN_powerpc64=	fails to link: checking linkage with boost::test... no

LIB_DEPENDS=	${PY_BOOST} \
		libpcre.so:devel/pcre \
		libxml2.so:textproc/libxml2

USES=		autoreconf compiler libtool pkgconfig python:2.7 ssl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--with-boost-prefix=${LOCALBASE} \
		--with-pcre-prefix=${LOCALBASE} \
		--enable-python --disable-perl --disable-tests \
		--disable-java --disable-nodejs
CONFIGURE_ENV=	crypto_CFLAGS="-I${OPENSSLINC}" \
		crypto_LIBS="-L${OPENSSLLIB} -lcrypto"
CPPFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

post-patch:
	@${REINPLACE_CMD} -e 's/\[boost_python]/[${PY_BOOST_LIB}]/' \
		${WRKSRC}/config/ax_boost_python.m4

.include <bsd.port.mk>
