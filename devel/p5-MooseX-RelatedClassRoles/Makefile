# New ports collection makefile for:	MooseX-RelatedClassRoles
# Date created:	                        January 31, 2010
# Whom:		                        	Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	MooseX-RelatedClassRoles
PORTVERSION=	0.004
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Apply roles to a class related to yours

BUILD_DEPENDS=	\
	p5-Moose>=2:${PORTSDIR}/devel/p5-Moose \
	p5-MooseX-Role-Parameterized>=0.04:${PORTSDIR}/devel/p5-MooseX-Role-Parameterized
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	MooseX::RelatedClassRoles.3

.include <bsd.port.mk>
