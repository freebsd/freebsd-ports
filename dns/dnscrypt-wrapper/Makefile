# $FreeBSD$

PORTNAME=	dnscrypt-wrapper
PORTVERSION=	0.2
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	dns

MAINTAINER=	freebsd@toyingwithfate.com
COMMENT=	Adds dnscrypt support to any name resolver

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsodium.so:security/libsodium \
		libevent.so:devel/libevent2

USE_GITHUB=	yes
GH_ACCOUNT=	Cofyc

USERS=		_dnscrypt-wrapper
ETCDNSCRYPTWRAPPER=	${PREFIX}/etc/${PORTNAME}
SUB_LIST+=	ETCDNSCRYPTWRAPPER="${ETCDNSCRYPTWRAPPER}" USERS="${USERS}"
USE_RC_SUBR=	${PORTNAME}

USES=		gmake
MAKE_ARGS=	LDFLAGS="-L${LOCALBASE}/lib" CFLAGS="-I${LOCALBASE}/include" PREFIX="${STAGEDIR}${PREFIX}"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/*
	${MKDIR} ${STAGEDIR}${ETCDNSCRYPTWRAPPER}

.include <bsd.port.mk>
