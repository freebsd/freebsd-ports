PORTNAME=	libhsclient
DISTVERSION=	1.0.6-20110614
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://people.cs.nycu.edu.tw/~jnlin/distfiles/
DISTNAME=	HandlerSocket-Plugin-for-MySQL-${DISTVERSION}

MAINTAINER=	jnlin@freebsd.cs.nctu.edu.tw
COMMENT=	Client Library of HandlerSocket Plugin
WWW=		https://github.com/ahiguti/HandlerSocket-Plugin-for-MySQL

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool
USE_CXXSTD=	c++14

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-handlersocket-server=no

WRKSRC=		${WRKDIR}/HandlerSocket-Plugin-for-MySQL

.include <bsd.port.mk>
