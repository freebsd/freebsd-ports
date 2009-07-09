# New ports collection makefile for:	p5-Data-Postponed
# Date created:				22 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-Postponed
PORTVERSION=	0.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Delay the evaluation of expressions to allow changes to variables

BUILD_DEPENDS=	p5-Scalar-List-Utils>0:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

DEPRECATED=	the module was removed from CPAN
EXPIRATION_DATE=	2009-09-09

MAN3=	Data::Postponed.3 \
	Data::Postponed::Forever.3 \
	Data::Postponed::Once.3 \
	Data::Postponed::OnceOnly.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
