# New ports collection makefile for:	p5-Class-Accessor-Named
# Date created:		2006-07-21
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Class-Accessor-Named
PORTVERSION=	0.009
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Better profiling output for Class::Accessor

RUN_DEPENDS=	p5-Sub-Name>=0:${PORTSDIR}/devel/p5-Sub-Name \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Hook-LexWrap>=0:${PORTSDIR}/devel/p5-Hook-LexWrap \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::Accessor::Named.3

.include <bsd.port.mk>
