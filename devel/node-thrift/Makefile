# New ports collection makefile for:	node-thrift
# Date created:				2012-01-02
# Whom:					Valery Komarov <komarov@valerka.net>
#
# $FreeBSD$
#

PORTNAME=	thrift
PORTVERSION=	${THRIFT_PORTVERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	node-
DISTFILES=	# empty

MAINTAINER=	komarov@valerka.net
COMMENT=	Node.js bindings for the Apache Thrift RPC system

RUN_DEPENDS=		node:${PORTSDIR}/www/node
EXTRACT_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/thrift:extract

NO_BUILD=	yes

.include <bsd.port.pre.mk>

do-install:
	${CP} -R \
	`${MAKE} -C ${PORTSDIR}/devel/thrift -V WRKSRC`/lib/nodejs \
		${PREFIX}/lib/node_modules/thrift
	${LN} -s ${PREFIX}/lib/node_modules/thrift/lib/thrift ${PREFIX}/lib/node

.include "${PORTSDIR}/devel/thrift/bsd.thrift.mk"
.include <bsd.port.post.mk>
