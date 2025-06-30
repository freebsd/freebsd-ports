PORTNAME=	umurmur
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	audio net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Minimalistic Murmur (Mumble server)
WWW=		https://umurmur.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libconfig.so:devel/libconfig \
		libprotobuf-c.so:devel/protobuf-c

USES=		cmake ssl
USE_GITHUB=	yes
USE_RC_SUBR=	umurmur

USERS=	${PORTNAME}
GROUPS=	${PORTNAME}

PLIST_SUB=	USER=${USERS} \
		GROUP=${GROUPS}

SUB_LIST=	USER=${USERS}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/conf.c
	@${REINPLACE_CMD} \
		-e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/umurmur.conf.example
	@${REINPLACE_CMD} -e 's|0.3.0|0.3.1|g' ${WRKSRC}/src/version.h

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/umurmur
	${INSTALL_DATA} ${WRKSRC}/umurmur.conf.example ${STAGEDIR}${PREFIX}/etc/umurmur/umurmur.conf.sample
	${MKDIR} ${STAGEDIR}/var/run/umurmur

.include <bsd.port.mk>
