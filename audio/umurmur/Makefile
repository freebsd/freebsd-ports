PORTNAME=	umurmur
DISTVERSION=	0.3.0
CATEGORIES=	audio net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Minimalistic Murmur (Mumble server)
WWW=		https://umurmur.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libconfig.so:devel/libconfig \
		libmbedtls.so:security/mbedtls3 \
		libprotobuf-c.so:devel/protobuf-c

USES=		autoreconf gmake libtool localbase
USE_GITHUB=	yes
USE_RC_SUBR=	umurmur

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ssl=mbedtls

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/conf.c
	@${REINPLACE_CMD} \
		-e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/umurmur.conf.example

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/umurmur
	${INSTALL_DATA} ${WRKSRC}/umurmur.conf.example ${STAGEDIR}${PREFIX}/etc/umurmur/umurmur.conf.sample

.include <bsd.port.mk>
