# New ports collection makefile for:	thrift
# Date created:	   27 September 2007
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	thrift
PORTVERSION=	20070917
CATEGORIES=	devel
PKGNAMEPREFIX=	ruby-
DISTFILES=

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Ruby interface to thrift

BROKEN=		needs updating for Apache Incubator version

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/thrift:extract

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

post-extract:
	@${LN} -sfh \
	`cd ${PORTSDIR}/devel/thrift && ${MAKE} -V WRKSRC`/lib/rb ${WRKSRC}

.include <bsd.port.mk>
