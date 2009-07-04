# New ports collection makefile for:	thrift
# Date created:	   27 September 2007
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	thrift
PORTVERSION=	20090622
CATEGORIES=	devel
PKGNAMEPREFIX=	ruby-
DISTFILES=

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Ruby interface to thrift

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/thrift:extract

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

# XXX: Because this port will call ruby again to build binary extensions,
# it is not suitable for building when PREFIX != LOCALBASE.
# This seems to be a Ruby limitation, and the following does not help:
#USE_RUBY_EXTCONF=	yes
#RUBY_EXTCONF_SUBDIRS=	ext

post-extract:
	@${LN} -sfh \
	`cd ${PORTSDIR}/devel/thrift && ${MAKE} -V WRKSRC`/lib/rb ${WRKSRC}

.include <bsd.port.mk>
