# New ports collection makefile for:	gonzui
# Date created:	Wed Dec  1 16:35:00 GMT 2004
# Whom:		sumikawa
#
# $FreeBSD$
#

PORTNAME=	gonzui
PORTVERSION=	0.2
CATEGORIES=	devel
MASTER_SITES=	http://namazu.org/~satoru/gonzui/

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=		A source code search engine

BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb

USE_RUBY=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
