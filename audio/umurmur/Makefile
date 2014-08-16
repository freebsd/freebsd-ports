# Created by: Ayumi Mitsui <ayu@commun.jp>
# $FreeBSD$

PORTNAME=	umurmur
PORTVERSION=	0.2.15
CATEGORIES=	audio net

MAINTAINER=	ayu@commun.jp
COMMENT=	Minimalistic Murmur (Mumble server)

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libconfig.so:${PORTSDIR}/devel/libconfig \
		libprotobuf-c.so:${PORTSDIR}/devel/protobuf-c

USE_GITHUB=	yes
GH_ACCOUNT=	fatbob313
GH_COMMIT=	17daa7e

USES=		gmake libtool
USE_AUTOTOOLS=	aclocal autoconf autoheader automake
AUTOMAKE_ARGS=	--add-missing
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--with-ssl=openssl

USE_RC_SUBR=	umurmur

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/conf.c
	@${REINPLACE_CMD} \
		-e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/umurmur.conf.example

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/umurmur
	${INSTALL_DATA} ${WRKSRC}/umurmur.conf.example ${STAGEDIR}${PREFIX}/etc/umurmur/umurmur.conf.sample

.include <bsd.port.mk>
