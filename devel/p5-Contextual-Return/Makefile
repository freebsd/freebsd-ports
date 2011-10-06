# New ports collection makefile for:	p5-Contextual-Return
# Date created:		2006-08-09
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Contextual-Return
PORTVERSION=	0.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DCONWAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create context-senstive return values

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Want.pm:${PORTSDIR}/devel/p5-Want \
		${SITE_PERL}/${PERL_ARCH}/version.pm:${PORTSDIR}/devel/p5-version
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Contextual::Return.3 Contextual::Return::Failure.3

.include <bsd.port.mk>
