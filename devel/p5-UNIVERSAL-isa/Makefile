# New ports collection makefile for:	p5-UNIVERSAL-isa
# Date Created:				16 Nov, 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	UNIVERSAL-isa
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Try to recover from people calling UNIVERSAL::isa as a function

BUILD_DEPENDS=	p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	5.6.2+

MAN3=		UNIVERSAL::isa.3

.include <bsd.port.mk>
