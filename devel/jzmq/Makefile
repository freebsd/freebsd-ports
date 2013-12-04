# $FreeBSD$

PORTNAME=	jzmq
PORTVERSION=	2011.04.26
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	LOCAL/olgeni
DISTNAME=	zeromq-${PORTNAME}-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Java bindings for ZeroMQ

LIB_DEPENDS=	zmq.1:${PORTSDIR}/net/libzmq2

USES=		pkgconfig
USE_AUTOTOOLS=	autoconf:env libtool automake:env
USE_GMAKE=	yes
USE_JAVA=	1.4+
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--with-zeromq=${LOCALBASE}
CONFIGURE_ENV=	JAVA_HOME=${JAVA_HOME}
LDFLAGS+=	-pthread
GNU_CONFIGURE=	yes

PLIST_FILES=	%%JAVAJARDIR%%/zmq.jar	\
		%%LIB32DIR%%/libjzmq.a	\
		%%LIB32DIR%%/libjzmq.la	\
		%%LIB32DIR%%/libjzmq.so	\
		%%LIB32DIR%%/libjzmq.so.0

NO_STAGE=	yes
pre-configure:
	@${MKDIR} ${WRKSRC}/config
	@cd ${WRKSRC} && ${AUTORECONF} --install --force --verbose -I config

.include <bsd.port.mk>
