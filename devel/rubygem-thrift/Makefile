# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	thrift
PORTVERSION=	${THRIFT_PORTVERSION} # to keep in sync with ../thrift
PORTEPOCH=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	komarov@valerka.net
COMMENT=	Ruby interface to thrift

LICENSE=	APACHE20

USE_RUBY=	yes
USES=		gem

# Workaround for stage-qa:
post-install:
	${FIND} ${STAGEDIR}${PREFIX}/${GEMS_BASE_DIR}/ -name '*.o' -o -name '*.so' | ${XARGS} ${STRIP_CMD}

.include "../thrift/bsd.thrift.mk"
.include <bsd.port.mk>
