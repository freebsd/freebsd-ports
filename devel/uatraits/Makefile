# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uatraits
PORTVERSION=	20121112
PORTREVISION=	2
CATEGORIES=	devel www
MASTER_SITES=	http://people.freebsd.org/~demon/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	User-Agent detection library

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf \
		automake:${PORTSDIR}/devel/automake \
		libtool:${PORTSDIR}/devel/libtool
LIB_DEPENDS=	boost_python:${PORTSDIR}/devel/boost-python-libs \
		pcre:${PORTSDIR}/devel/pcre \
		xml2:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if exists(${PYTHON_CMD}-config)
PYLIBS!=	${PYTHON_CMD}-config --libs
.endif
CONFIGURE_ARGS+=	--with-boost-prefix=${LOCALBASE} \
			--with-pcre-prefix=${LOCALBASE} \
			--enable-python --disable-perl --disable-tests \
			--disable-java --disable-nodejs
CPPFLAGS+=	"-I${LOCALBASE}/include"
CONFIGURE_ENV+=		crypto_CFLAGS="-I${OPENSSLINC}" \
			crypto_LIBS="-L${OPENSSLLIB} -lcrypto" \
			PYTHON_LIBS="${PYLIBS} -L${LOCALBASE}/lib"

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.post.mk>
