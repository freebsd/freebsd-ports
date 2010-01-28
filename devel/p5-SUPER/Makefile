# New ports collection makefile for:	devel/p5-SUPER
# Date created:				12 June, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	SUPER
PORTVERSION=	1.17
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Perl module control superclass method dispatch

BUILD_DEPENDS=	p5-Sub-Identify>=0.04:${PORTSDIR}/devel/p5-Sub-Identify \
		p5-Scalar-List-Utils>=0.20:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
PERL_MODBUILD=	yes

MAN3=	SUPER.3

.include <bsd.port.mk>
