# New ports collection makefile for:	Class-Accessor
# Date created:		17 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Class-Accessor
PORTVERSION=	0.19
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Automated accessor generation

PERL_CONFIGURE=	yes

MAN3=		Class::Accessor.3 Class::Accessor::Fast.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
BUILD_DEPENDS=  ${SITE_PERL}/base.pm:${PORTSDIR}/devel/p5-Class-Fields
RUN_DEPENDS=    ${BUILD_DEPENDS}
.endif

.include <bsd.port.post.mk>
