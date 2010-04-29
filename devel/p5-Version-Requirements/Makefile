# New ports collection makefile for:	p5-Version-Requirements
# Date created:				April 20 2010
# Whom:					jupengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Version-Requirements
PORTVERSION=	0.101020
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/R/RJ/RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	jupengfei@gmail.com
COMMENT=	A set of version requirements for a CPAN dist

BUILD_DEPENDS=	p5-Test-Simple>0:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Version::Requirements.3

.include <bsd.port.mk>
