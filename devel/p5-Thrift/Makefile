# New ports collection makefile for:	Thrift
# Date created:	   27 September 2007
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Thrift
PORTVERSION=	${THRIFT_PORTVERSION}	# need to keep this in sync with ../thrift see ../thrift/bsd.thrift.mk
PORTEPOCH=	1
CATEGORIES=	devel perl5
PKGNAMEPREFIX=	p5-
DISTFILES=

MAINTAINER=	komarov@valerka.net
COMMENT=	Perl interface to Thrift

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Bit/Vector.pm:${PORTSDIR}/math/p5-Bit-Vector
BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/thrift:extract \
		${SITE_PERL}/${PERL_ARCH}/Bit/Vector.pm:${PORTSDIR}/math/p5-Bit-Vector

PERL_CONFIGURE=	YES

post-extract:
	@${LN} -sfh \
	`cd ${PORTSDIR}/devel/thrift && ${MAKE} -V WRKSRC`/lib/perl ${WRKSRC}

.include "../thrift/bsd.thrift.mk"
.include <bsd.port.mk>
