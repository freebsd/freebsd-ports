PORTNAME=	webdis
DISTVERSION=	0.1.25
CATEGORIES=	databases

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	HTTP interface for Redis
WWW=		https://webd.is/

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	nicolasff
USE_RC_SUBR=	webdis

USERS=		webdis
GROUPS=		webdis

PLIST_FILES=	bin/webdis \
		"@sample etc/webdis.conf.sample"

OPTIONS_DEFINE=		MSGPACK
OPTIONS_DEFAULT=	MSGPACK

MSGPACK_DESC=		MessagePack output format support
MSGPACK_LIB_DEPENDS=	libmsgpack-c.so:devel/msgpack-c
MSGPACK_USES=		pkgconfig
MSGPACK_MAKE_ARGS=	MSGPACK=1
MSGPACK_MAKE_ARGS_OFF=	MSGPACK=0

post-patch:
	${REINPLACE_CMD} -e "s@%%LOCALBASE%%@${LOCALBASE}@g" ${WRKSRC}/Makefile

do-install:
	${INSTALL} ${WRKSRC}/webdis ${STAGEDIR}${PREFIX}/bin/webdis
	${INSTALL_DATA} ${FILESDIR}/webdis.conf ${STAGEDIR}${PREFIX}/etc/webdis.conf.sample

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/webdis

.include <bsd.port.mk>
