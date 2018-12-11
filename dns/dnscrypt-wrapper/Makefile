# $FreeBSD$

PORTNAME=	dnscrypt-wrapper
PORTVERSION=	0.4.2
DISTVERSIONPREFIX=	v
CATEGORIES=	dns

MAINTAINER=	freebsd@toyingwithfate.com
COMMENT=	Adds dnscrypt support to any name resolver

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsodium.so:security/libsodium \
		libevent.so:devel/libevent

USE_GITHUB=	yes
GH_ACCOUNT=	cofyc

USERS=		_dnscrypt-wrapper
ETCDNSCRYPTWRAPPER=	${PREFIX}/etc/${PORTNAME}
SUB_LIST+=	ETCDNSCRYPTWRAPPER="${ETCDNSCRYPTWRAPPER}" USERS="${USERS}"
USE_RC_SUBR=	${PORTNAME}

USES=		gmake localbase:ldflags

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/*
	@${MKDIR} ${STAGEDIR}${ETCDNSCRYPTWRAPPER}

.include <bsd.port.mk>
