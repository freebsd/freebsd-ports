# New ports collection makefile for:	mingplot
# Date created:				14 Nov 2003
# Whom:					UMENO Takashi <umeno@rr.iij4u.or.jp>
#
# $FreeBSD$
#

PORTNAME=	mingplot
PORTVERSION=	0.2
CATEGORIES=	graphics www
MASTER_SITES=	http://namazu.org/~satoru/mingplot/

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	A tool to generate a flash-based chart

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/ming/ming.so:${PORTSDIR}/graphics/ruby-ming \
		${RUBY_SITEARCHLIBDIR}/iconv.so:${PORTSDIR}/converters/ruby-iconv

USE_RUBY=	yes

.include <bsd.port.mk>
