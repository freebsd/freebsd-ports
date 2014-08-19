# Created by: UMENO Takashi <umeno@rr.iij4u.or.jp>
# $FreeBSD$

PORTNAME=	mingplot
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	graphics www
MASTER_SITES=	http://0xcc.net/mingplot/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to generate a flash-based chart

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/ming/mingc.so:${PORTSDIR}/graphics/ruby-ming

USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv

DEPRECATED=	Depends on deprecated graphics/ruby-ming
EXPIRATION_DATE=        2014-09-20

NO_STAGE=	yes
.include <bsd.port.mk>
