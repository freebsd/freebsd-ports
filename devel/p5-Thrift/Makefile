# New ports collection makefile for:	Thrift
# Date created:	   27 September 2007
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Thrift
PORTVERSION=	20090622
CATEGORIES=	devel perl5
PKGNAMEPREFIX=	p5-
DISTFILES=

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perl interface to Thrift

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Bit/Vector.pm:${PORTSDIR}/math/p5-Bit-Vector
BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/thrift:extract \
		${SITE_PERL}/${PERL_ARCH}/Bit/Vector.pm:${PORTSDIR}/math/p5-Bit-Vector

PERL_CONFIGURE=	5.6.0+

post-extract:
	@${LN} -sfh \
	`cd ${PORTSDIR}/devel/thrift && ${MAKE} -V WRKSRC`/lib/perl ${WRKSRC}

.include <bsd.port.mk>
