# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	libhsclient
PORTVERSION=	1.0.6
PORTREVISION=	${REVISION}
CATEGORIES=	databases
MASTER_SITES=	http://www.cs.nctu.edu.tw/~jnlin/distfiles/
DISTNAME=	HandlerSocket-Plugin-for-MySQL-${PORTVERSION}-${REVISION}

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	Client Library of HandlerSocket Plugin

WRKSRC=		${WRKDIR}/HandlerSocket-Plugin-for-MySQL

REVISION=	20110614

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-handlersocket-server=no

NO_STAGE=	yes
.include <bsd.port.mk>
